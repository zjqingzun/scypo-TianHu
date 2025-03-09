#!/bin/bash
LOG_FILE="config/logs/output.log"

echo "=== Chạy kiểm thử ===" | tee -a "$LOG_FILE"
./scripts/run.sh "$1"
echo "=== Phân tích lỗi ===" | tee -a "$LOG_FILE"
perl scripts/log_parser.pl
echo "=== Kiểm thử hoàn tất ===" | tee -a "$LOG_FILE"
