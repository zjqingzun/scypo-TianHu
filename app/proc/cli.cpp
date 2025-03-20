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

        // Exit
        if (_ccu == "exit") break;

        // CLI - Command CLI
        Controller CLI_;
        if (CLI_.__splitString(_ccu)) {
            CLI_.__CommandCLI();
            //CLI_.__displayParts();
            std::cout << std::endl;
            __decen0momoCCU(CLI_);
        }
        
        if (CLI_.__getMomo() == "cls" || CLI_.__getMomo() == "clear") {
            system("cls");
        }

        if (CLI_.__getMomo() == "error") {
            std::cout << _ccu << ": command not found" << std::endl;
        }
        
        _ccu = "";
    }
}