#include "test.h"




// Function Definitions
void __test000001() {
    // TEST ----------------------------------ciph and secrust
    const char* _data = "test";
    size_t _len = 4;

    int _encrypted = __ciphEncrypt((const unsigned char*)_data, _len);
    std::cout << "\nEncrypted value: " << _encrypted << std::endl;

    int _hashed = __secrustHash((const unsigned char*)_data, _len);
    std::cout << "Hashed value: " << _hashed << std::endl;
}

void __test000002() {
    // TEST ----------------------------------zerotrace
    int _result = zerotrace_scan("127.0.0.1", "80-100", 0, 500, 20, -1, NULL);
    if (_result == 0) {
        printf("Scan completed successfully\n");
    } else {
        printf("01:  !(app/proc/test.cpp)\nScan failed with error: %d\n", _result);
    }
}

int __test000003() {
    // TEST ----------------------------------app/core/bin
    // Dữ liệu lớn để thử nghiệm
    const char* largeData = "This is a large data sample for testing binary file operations!";
    size_t dataSize = strlen(largeData);

    // Ghi dữ liệu vào file
    if (saveToBinaryFile("large_data.bin", largeData, dataSize)) {
        printf("Successfully saved data to large_data.bin\n");
    } else {
        printf("Failed to save data\n");
        return 1;
    }

    // Đọc dữ liệu từ file
    char* buffer = NULL;
    size_t readSize = 0;
    if (readFromBinaryFile("large_data.bin", &buffer, &readSize)) {
        printf("Successfully read %zu bytes from file\n", readSize);
    
        // In dữ liệu ra màn hình
        printBinaryData(buffer, readSize);
        
        free(buffer);  // Giải phóng bộ nhớ
    } else {
        printf("Failed to read data\n");
        return 1;
    }

    return 0;
}