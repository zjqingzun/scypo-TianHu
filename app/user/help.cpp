#include "user.h"




// Function Definitions
bool __helpZmain(std::string _exec, std::string _stdd, std::string _pack) {
    if (_exec == "") {
        const char *_fileName = "resrc/sys-doc/guide.txt";
        FILE* _file = __fileOpen(_fileName, "r");
        if (!_file) {
            __erno__("400");
        }
        else {
            __fileReadByLine(_file);
            __fileClose(_file);
        }
        return true;
    }
    return false;
}