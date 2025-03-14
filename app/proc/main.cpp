#include "syssware.h"
//#include "../../include/cxx-secrust/ciph.h"
//#include "../../include/cxx-secrust/secrust.h"
//#include "../../include/cxx-secrust/zerotrace.h"




int main() {
    __CCU__();

    // TEST ----------------------------------ciph and secrust
    // const char* data = "test";
    // size_t len = 4;

    // int encrypted = __ciphEncrypt((const unsigned char*)data, len);
    // std::cout << "\nEncrypted value: " << encrypted << std::endl;

    // int hashed = __secrustHash((const unsigned char*)data, len);
    // std::cout << "Hashed value: " << hashed << std::endl;

    // TEST ----------------------------------zerotrace
    // int result = zerotrace_scan("127.0.0.1", "80-100", 0, 500, 20, -1, NULL);
    // if (result == 0) {
    //     printf("Scan completed successfully\n");
    // } else {
    //     printf("Scan failed with error: %d\n", result);
    // }

    return 0;
}