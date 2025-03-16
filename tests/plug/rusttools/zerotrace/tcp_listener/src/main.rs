use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};




// Function Definitions
fn __handleClient(mut _stream: TcpStream) {
    let mut _buffer = [0; 1024];
    match _stream.read(&mut _buffer) {
        Ok(n) if n > 0 => {
            let received = String::from_utf8_lossy(&_buffer[..n]);
            println!("Received: {}", received);
            // Send feedback (optional)
            _stream.write_all(b"Received your message!").unwrap();
        }
        Ok(_) => println!("No data received"),
        Err(e) => println!("!(tests/plug/rusttools/zerotrace/tcp_listener/src/main.rs)\nFailed to read from stream: {}", e),
    }
}


// main()
fn main() {
    let _listener = TcpListener::bind("127.0.0.1:12345").unwrap();
    println!("Listening on 127.0.0.1:12345...");

    for stream in _listener.incoming() {
        match stream {
            Ok(stream) => {
                println!("New connection: {}", stream.peer_addr().unwrap());
                __handleClient(stream);
            }
            Err(e) => println!("!(tests/plug/rusttools/zerotrace/tcp_listener/src/main.rs)\nError accepting connection: {}", e),
        }
    }
}