#include "user.h"




// Function Definitions
int __userCopyright() {
    system("cls");

    const char *_fileName = "resrc/sys/copyright.txt";
    FILE* _file = __fileOpen(_fileName, "r");
    __fileReadByLine(_file);
    __fileClose(_file);
    return 0;
}