mod scanner;
mod packet;
mod utils;

use std::env;
use scanner::scan_port;
use packet::send_tcp_packet;
use utils::print_usage;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        print_usage();
        return;
    }

    let target = &args[1];
    let port: u16 = match args[2].parse() {
        Ok(p) => p,
        Err(_) => {
            println!("Invalid port number!");
            return;
        }
    };

    // Thử quét cổng trước
    println!("Scanning target {} on port {}", target, port);
    match scan_port(target, port) {
        Ok(is_open) => {
            if is_open {
                println!("Port {} is open", port);
                // Thử gửi gói tin nếu cổng mở
                match send_tcp_packet(target, port, b"Hello, Zerotrace!") {
                    Ok(_) => println!("Packet sent successfully"),
                    Err(e) => println!("Failed to send packet: {}", e),
                }
            } else {
                println!("Port {} is closed", port);
            }
        }
        Err(e) => println!("Error scanning port: {}", e),
    }
}