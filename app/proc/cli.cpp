#include "syssware.h"




// Function Definitions
void __CCU__() {
    // Encrypt


    // Copyright 
    __userCopyright();


    std::string _ccu = "";
    while (true) {
        // Input
        std::cout << ">>>>\t";
        getline(std::cin, _ccu);

        
        // Empty char
        


        // Exit
        if (_ccu == "exit") break;


        // CLI - Command CLI
        Controller CLI_;
        if (CLI_.__splitString(_ccu)) {
            CLI_.__CommandCLI();
            CLI_.__displayParts();
        }
        
        if (CLI_.__getMomo() == "cls") 
            system("cls");
        _ccu = "";
    }
}