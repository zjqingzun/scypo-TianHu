use std::net::{TcpStream, UdpSocket, IpAddr};
use std::str::FromStr;
use std::time::Duration;

pub fn scan_tcp_port(target: &str, port: u16, timeout_ms: u64) -> Result<bool, String> {
    let ip = match IpAddr::from_str(target) {
        Ok(ip) => ip,
        Err(_) => return Err("Invalid IP address".to_string()),
    };

    let address = format!("{}:{}", ip, port);
    match TcpStream::connect_timeout(
        &address.parse().map_err(|_| "Failed to parse address")?,
        Duration::from_millis(timeout_ms), // Giảm timeout xuống còn tùy chỉnh (mặc định 500ms)
    ) {
        Ok(_) => Ok(true),
        Err(_) => Ok(false),
    }
}

pub fn scan_udp_port(target: &str, port: u16, timeout_ms: u64) -> Result<bool, String> {
    let ip = match IpAddr::from_str(target) {
        Ok(ip) => ip,
        Err(_) => return Err("Invalid IP address".to_string()),
    };

    let socket = match UdpSocket::bind("0.0.0.0:0") {
        Ok(s) => s,
        Err(_) => return Err("Failed to bind UDP socket".to_string()),
    };

    socket
        .set_read_timeout(Some(Duration::from_millis(timeout_ms)))
        .map_err(|_| "Failed to set timeout".to_string())?;

    let address = format!("{}:{}", ip, port);
    let payload = b"probe";
    match socket.send_to(payload, &address) {
        Ok(_) => {
            let mut buf = [0; 1024];
            match socket.recv_from(&mut buf) {
                Ok(_) => Ok(true),
                Err(_) => Ok(false),
            }
        }
        Err(_) => Ok(false),
    }
}

// Hàm quét một cổng duy nhất (dùng trong đa luồng)
pub fn scan_single_port(target: &str, port: u16, use_udp: bool, timeout_ms: u64) -> (u16, bool) {
    let result = if use_udp {
        scan_udp_port(target, port, timeout_ms)
    } else {
        scan_tcp_port(target, port, timeout_ms)
    };
    match result {
        Ok(is_open) => (port, is_open),
        Err(_) => (port, false),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_scan_port_invalid_ip() {
        let result = scan_port("invalid_ip", 80);
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Invalid IP address");
    }

    #[test]
    fn test_scan_port_closed() {
        // Giả sử cổng 54321 không có dịch vụ chạy
        let result = scan_port("127.0.0.1", 54321);
        assert!(result.is_ok());
        assert_eq!(result.unwrap(), false); // Cổng đóng
    }

    #[test]
    fn test_scan_port_open() {
        // Giả sử có một dịch vụ chạy trên cổng 80 (web server)
        let result = scan_port("127.0.0.1", 80);
        assert!(result.is_ok());
        // Kết quả phụ thuộc vào việc cổng 80 có mở hay không
        // Nếu bạn có web server chạy, điều chỉnh kỳ vọng cho phù hợp
    }
}