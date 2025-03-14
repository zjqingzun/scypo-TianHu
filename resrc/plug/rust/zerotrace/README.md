# Zerotrace

A minimal network scanning library inspired by Kali Linux's zerotrace, built in Rust and designed for integration with C/C++ projects as a dynamic library.

## Features
- Basic TCP and UDP port scanning
- Scan single port or port range
- Optional random delay between scans for basic anonymity
- Save scan results to a log file
- Multithreaded scanning for improved performance
- Progress indicator and scan duration display

## Building the Library
1. Clone the repository and navigate to the project directory:
   ```bash
   git clone <repository-url>
   cd zerotrace