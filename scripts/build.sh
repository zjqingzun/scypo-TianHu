#!/bin/bash
LOG_FILE="config/logs/output.log"

echo "=== Bắt đầu biên dịch ===" | tee -a "$LOG_FILE"

# Gọi make từ PowerShell thay vì Bash
powershell.exe -Command "make all"

echo "=== Hoàn thành biên dịch ===" | tee -a "$LOG_FILE"
