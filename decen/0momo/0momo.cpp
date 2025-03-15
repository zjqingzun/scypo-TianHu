#include "../utils-0momo.h"




// Function Definitions
void __decen0momoCCU(Controller& ccu_) {
    // Interface
    if (ccu_.__getMomo() == "interface" || ccu_.__getMomo() == "gui") {
        std::cout << "User interface has been changed. \n\n";
        
    }

    // Mode
    if (__decen0mode(ccu_)) {
        std::cout << "\n";
    }

    // Module
    if (__decen0module(ccu_)) {
        std::cout << "\n";
    }
}