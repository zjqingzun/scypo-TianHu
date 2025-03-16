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
        printf("!(app/proc/test.cpp) Scan failed with error: %d\n", _result);
    }
}