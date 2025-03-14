use std::net::{TcpStream, IpAddr};
use std::io::Write;
use std::str::FromStr;
use std::thread;
use std::time::Duration;
use rand::Rng;

pub fn send_tcp_packet(target: &str, port: u16, payload: &[u8], delay_ms: Option<u64>) -> Result<(), String> {
    let ip = match IpAddr::from_str(target) {
        Ok(ip) => ip,
        Err(_) => return Err("Invalid IP address".to_string()),
    };

    if let Some(delay) = delay_ms {
        let random_delay = rand::thread_rng().gen_range(0..delay);
        thread::sleep(Duration::from_millis(random_delay));
    }

    let address = format!("{}:{}", ip, port);
    let mut stream = match TcpStream::connect_timeout(
        &address.parse().map_err(|_| "Failed to parse address")?,
        Duration::from_millis(500), // Giảm timeout xuống 500ms
    ) {
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
        let result = send_tcp_packet("invalid_ip", 80, b"test", None);
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Invalid IP address");
    }

    #[test]
    fn test_send_tcp_packet_closed_port() {
        let result = send_tcp_packet("127.0.0.1", 54321, b"test", None);
        assert!(result.is_err());
        assert_eq!(result.unwrap_err(), "Failed to connect to target");
    }
}