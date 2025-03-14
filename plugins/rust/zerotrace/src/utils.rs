use std::str::FromStr;

#[allow(dead_code)] // Thêm để tránh cảnh báo dead_code
pub fn print_usage() {
    println!("Usage: zerotrace <target_ip> <ports> [--log <file>] [--delay <ms>] [--udp] [--timeout <ms>] [--threads <n>]");
    println!("  <ports>: Single port (e.g., 80) or range (e.g., 80-100)");
    println!("  --log <file>: Save results to a log file");
    println!("  --delay <ms>: Add random delay between scans (in milliseconds)");
    println!("  --udp: Scan UDP ports instead of TCP");
    println!("  --timeout <ms>: Set timeout for each scan (default: 500ms)");
    println!("  --threads <n>: Set maximum number of threads (default: 50)");
    println!("Example: zerotrace 127.0.0.1 80-100 --log scan.log --delay 100 --timeout 300 --threads 20");
}

pub fn parse_ports(ports_str: &str) -> Result<Vec<u16>, String> {
    if ports_str.contains('-') {
        let parts: Vec<&str> = ports_str.split('-').collect();
        if parts.len() != 2 {
            return Err("Invalid port range format".to_string());
        }
        let start = u16::from_str(parts[0]).map_err(|_| "Invalid start port".to_string())?;
        let end = u16::from_str(parts[1]).map_err(|_| "Invalid end port".to_string())?;
        if start > end || start == 0 || end == 0 {
            return Err("Invalid port range".to_string());
        }
        Ok((start..=end).collect())
    } else {
        let port = u16::from_str(ports_str).map_err(|_| "Invalid port number".to_string())?;
        if port == 0 {
            return Err("Port cannot be 0".to_string());
        }
        Ok(vec![port])
    }
}