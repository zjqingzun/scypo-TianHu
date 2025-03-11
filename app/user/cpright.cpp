#include "user.h"




// Function Definitions
int __userCopyright() {
    const char *_fileName = "resrc/sys/copyright.txt";

    FILE* _file = __fileOpen(_fileName, "r");
    
    char* _data = __fileReadWord(_file);

    std::cout << _data << "\n\n";

    __fileClose(_file);
    return 0;
}