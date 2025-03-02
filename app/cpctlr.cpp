// Library
#include "cpctlr.h"




// Function Definitions
void __normalMode(char* mode) {
    std::string _mode = std::string() + mode;
    std::string mdls = std::string() + __getFirstWord(mode);
    
}


void __anlsMode(char* mode) {
    std::string _mode = std::string() + mode;
    printf("Analysis Mode\n");
    printf("Mode: %s\n", mode);
}


void __calcMode(char* mode) {
    std::string _mode = std::string() + mode;
    printf("Calculation Mode\n");
    printf("Mode: %s\n", mode);
}


void __taskMode(char* mode) {
    std::string _mode = std::string() + mode;

    std::istringstream _in(_mode);
    std::string _buffer;

    getline(_in, _buffer, ' ');
    getline(_in, _buffer, ' ');

    if (_buffer == "-py") {
        system("cls");
        __convertPython();
    }
    else {
        __printError("IN000001", _mode.c_str());
    }
}

