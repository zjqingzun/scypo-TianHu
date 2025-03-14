use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};

fn handle_client(mut stream: TcpStream) {
    let mut buffer = [0; 1024];
    match stream.read(&mut buffer) {
        Ok(n) if n > 0 => {
            let received = String::from_utf8_lossy(&buffer[..n]);
            println!("Received: {}", received);
            // Gửi phản hồi (tùy chọn)
            stream.write_all(b"Received your message!").unwrap();
        }
        Ok(_) => println!("No data received"),
        Err(e) => println!("Failed to read from stream: {}", e),
    }
}

fn main() {
    let listener = TcpListener::bind("127.0.0.1:12345").unwrap();
    println!("Listening on 127.0.0.1:12345...");

    for stream in listener.incoming() {
        match stream {
            Ok(stream) => {
                println!("New connection: {}", stream.peer_addr().unwrap());
                handle_client(stream);
            }
            Err(e) => println!("Error accepting connection: {}", e),
        }
    }
}