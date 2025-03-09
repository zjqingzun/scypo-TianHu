#!/bin/bash
LOG_FILE="config/logs/output.log"

echo "=== Dọn dẹp file biên dịch ===" | tee -a "$LOG_FILE"
rm -f bin/TianHu.exe app/core/*.o app/proc/*.o app/user/*.o
echo "=== Dọn dẹp hoàn tất ===" | tee -a "$LOG_FILE"
