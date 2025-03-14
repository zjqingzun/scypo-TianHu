use std::net::{TcpStream, IpAddr};
use std::str::FromStr;
use std::time::Duration;

pub fn scan_port(target: &str, port: u16) -> Result<bool, String> {
    let ip = match IpAddr::from_str(target) {
        Ok(ip) => ip,
        Err(_) => return Err("Invalid IP address".to_string()),
    };

    let address = format!("{}:{}", ip, port);
    match TcpStream::connect_timeout(
        &address.parse().map_err(|_| "Failed to parse address")?,
        Duration::from_secs(2),
    ) {
        Ok(_) => Ok(true),
        Err(_) => Ok(false),
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