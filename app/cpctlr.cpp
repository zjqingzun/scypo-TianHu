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
    printf("Task Mode\n");
    printf("Mode: %s\n", mode);
}

