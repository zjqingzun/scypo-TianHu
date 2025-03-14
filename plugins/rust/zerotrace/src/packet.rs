use std::net::{TcpStream, IpAddr};
use std::io::Write;
use std::str::FromStr;

pub fn send_tcp_packet(target: &str, port: u16, payload: &[u8]) -> Result<(), String> {
    let ip = match IpAddr::from_str(target) {
        Ok(ip) => ip,
        Err(_) => return Err("Invalid IP address".to_string()),
    };

    let address = format!("{}:{}", ip, port);
    let mut stream = match TcpStream::connect(&address) {
        Ok(s) => s,
        Err(_) => return Err("Failed to connect to target".to_string()),
    };

    match stream.write_all(payload) {
        Ok(_) => Ok(()),
        Err(_) => Err("Failed to send packet".to_string()),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_send_tcp_packet_invalid_ip() {
        let result = send_tcp_packet("invalid_ip", 80, b"test");
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Invalid IP address");
    }

    #[test]
    fn test_send_tcp_packet_closed_port() {
        // Giả sử cổng 54321 không có dịch vụ chạy
        let result = send_tcp_packet("127.0.0.1", 54321, b"test");
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Failed to connect to target");
    }
}