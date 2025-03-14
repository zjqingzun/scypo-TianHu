#include <iostream>




// Function Declarations
#ifndef ZEROTRACE_H
#define ZEROTRACE_H

#ifdef __cplusplus
extern "C" {
#endif

// Hàm quét cổng từ thư viện zerotrace
// Trả về 0 nếu thành công, -1 nếu lỗi
int zerotrace_scan(
    const char* target,       // Địa chỉ IP mục tiêu
    const char* ports,        // Dải cổng (ví dụ: "80-100")
    int use_udp,              // 1 để quét UDP, 0 để quét TCP
    unsigned long long timeout_ms, // Thời gian chờ mỗi cổng (ms)
    unsigned long max_threads,     // Số luồng tối đa
    long long delay_ms,       // Độ trễ ngẫu nhiên giữa các lần gửi (ms), -1 nếu không dùng
    const char* log_file      // Đường dẫn file log, NULL nếu không ghi log
);

#ifdef __cplusplus
}
#endif

#endif // ZEROTRACE_H