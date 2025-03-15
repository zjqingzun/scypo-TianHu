#include "../utils-0momo.h"




// Function Definitions
void __decen0momoCCU(Controller& ccu_) {
    bool _flag = false;
    if (ccu_.__getMomo() == "cont")  _flag = true;

    // Interface
    if (ccu_.__getMomo() == "interface" || ccu_.__getMomo() == "gui") {
        if (!_flag) {        
            std::cout << "User interface has been changed. \n\n";
            _flag = true;
        }
    }

    // Mode
    if (__decen0mode(ccu_) && !_flag) {
        std::cout << "\n";
        _flag = true;
    }

    // Module
    if (__decen0module(ccu_) && !_flag) {
        std::cout << "\n";
        _flag = true;
    }

    if (!_flag) {
        std::cout << ccu_.__command() << ": command not found \n";
    }
}