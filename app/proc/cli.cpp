#include "syssware.h"




// Function Definitions
void __CCU__() {
    // Encrypt


    // Copyright 
    __userCopyright();


    std::string _ccu = "";
    while (true) {
        std::cout << ">>>>\t";
        getline(std::cin, _ccu);

        

        if (_ccu == "exit") break;

        Controller CLI_;
        CLI_.__splitString(_ccu);
    }
}