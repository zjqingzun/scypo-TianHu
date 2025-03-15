#include "../utils-0momo.h"




// Function Definitions
bool __decen0module(Controller& cmd_) {
    if (cmd_.__getMomo() == "help") 
    {
        std::cout << "Command: Help \n";
        return true;
    }

    return false;
}