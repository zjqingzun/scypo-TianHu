#include "../utils-0momo.h"




// Function Definitions
bool __decen0mode(Controller& cmd_) {
    if (cmd_.__getMomo() == "norm") {
        std::cout << "Mode: Normal \n\n";
        return true;
    }
    else if (cmd_.__getMomo() == "calc") {
        std::cout << "Mode: Calculate \n\n";
        return true;
    }
    else if (cmd_.__getMomo() == "task") {
        std::cout << "Mode: Task \n\n";
        return true;
    }
    else if (cmd_.__getMomo() == "anls") {
        std::cout << "Mode: Analysis \n\n";
        return true;
    }
    return false;
}