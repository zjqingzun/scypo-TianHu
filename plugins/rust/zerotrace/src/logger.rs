use std::fs::OpenOptions;
use std::io::{BufWriter, Write};
use std::time::SystemTime;

pub fn log_result(message: &str, log_file: &str) -> std::io::Result<()> {
    let file = OpenOptions::new()
        .create(true)
        .append(true)
        .open(log_file)?;
    
    let mut writer = BufWriter::new(file);
    let timestamp = SystemTime::now()
        .duration_since(SystemTime::UNIX_EPOCH)
        .unwrap()
        .as_secs();

    writeln!(writer, "[{}] {}", timestamp, message)?;
    writer.flush()?;
    Ok(())
}