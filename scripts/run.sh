#!/bin/bash
LOG_FILE="config/logs/output.log"
ERROR_LOG="config/logs/error.log"

echo "=== Chạy chương trình ===" | tee -a "$LOG_FILE"
./"$1" >> "$LOG_FILE" 2>> "$ERROR_LOG"
