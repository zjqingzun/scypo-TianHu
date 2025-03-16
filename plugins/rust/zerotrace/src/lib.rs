mod scanner;
mod packet;
mod utils;
mod logger;

use std::ffi::CStr;
use std::os::raw::{c_char, c_int};
use std::time::Instant;
use std::thread;
use std::sync::mpsc::channel;
use std::time::Duration;
use utils::parse_ports;
use scanner::scan_single_port;
use packet::send_tcp_packet;
use logger::log_result;




// Main function for port scanning, output for C++
#[unsafe(no_mangle)]
pub extern "C" fn zerotrace_scan(
    target: *const c_char,
    ports: *const c_char,
    use_udp: c_int,
    timeout_ms: u64,
    max_threads: usize,
    delay_ms: i64,
    log_file: *const c_char,
) -> c_int {
    // Chuyển đổi target từ C string sang Rust string
    let target = unsafe {
        if target.is_null() {
            return -1; // Lỗi nếu target là null
        }
        match CStr::from_ptr(target).to_str() {
            Ok(s) => s,
            Err(_) => return -1, // Lỗi nếu không phải UTF-8
        }
    };

    // Chuyển đổi ports từ C string sang Rust string
    let ports_str = unsafe {
        if ports.is_null() {
            return -1;
        }
        match CStr::from_ptr(ports).to_str() {
            Ok(s) => s,
            Err(_) => return -1,
        }
    };

    // Chuyển đổi log_file từ C string sang Option<String>
    let log_file = unsafe {
        if log_file.is_null() {
            None
        } else {
            match CStr::from_ptr(log_file).to_str() {
                Ok(s) => Some(s.to_string()),
                Err(_) => return -1,
            }
        }
    };

    // Chuyển đổi delay_ms từ i64 sang Option<u64>
    let delay_ms = if delay_ms >= 0 {
        Some(delay_ms as u64)
    } else {
        None
    };

    // Phân tích dải cổng
    let ports = match parse_ports(ports_str) {
        Ok(p) => p,
        Err(_) => return -1,
    };

    let use_udp = use_udp != 0;

    println!("Scanning target {} on ports {:?}", target, ports);

    // Đo thời gian quét
    let start_time = Instant::now();

    // Tạo kênh để giao tiếp giữa các luồng
    let (tx, rx) = channel();
    let mut handles = vec![];

    // Chia nhỏ danh sách cổng và quét song song
    for chunk in ports.chunks(max_threads) {
        let chunk = chunk.to_vec();
        let target = target.to_string();
        let tx = tx.clone();
        let handle = thread::spawn(move || {
            for port in chunk {
                let result = scan_single_port(&target, port, use_udp, timeout_ms);
                tx.send(result).unwrap();
            }
        });
        handles.push(handle);
    }

    // Đóng kênh gửi để tránh deadlock
    drop(tx);

    // Thu thập và xử lý kết quả
    let mut results: Vec<(u16, bool)> = rx.into_iter().collect();
    results.sort_by_key(|(port, _)| *port);

    let total_ports = ports.len();
    let mut processed = 0;

    for (port, is_open) in results {
        processed += 1;
        let status = if is_open { "open" } else { "closed" };
        let protocol = if use_udp { "UDP" } else { "TCP" };
        let message = format!("Port {} ({}) is {} [{}/{}]", port, protocol, status, processed, total_ports);
        println!("{}", message);

        if let Some(ref file) = log_file {
            if let Err(e) = log_result(&message, file) {
                println!("Failed to write to log: {}", e);
            }
        }

        if is_open {
            match send_tcp_packet(target, port, b"Hello, Zerotrace!", delay_ms) {
                Ok(_) => println!("Packet sent successfully to port {}", port),
                Err(e) => println!("Failed to send packet to port {}: {}", port, e),
            }
        }

        if delay_ms.is_some() {
            thread::sleep(Duration::from_millis(delay_ms.unwrap()));
        }
    }

    for handle in handles {
        handle.join().unwrap();
    }

    let elapsed = start_time.elapsed();
    println!("Scan completed in {:?}", elapsed);

    0 // Trả về 0 nếu thành công
}