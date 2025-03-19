#include "../utils-0momo.h"




// Function Definitions
bool __decen0module(Controller& cmd_) {
    if (cmd_.__getMomo() == "help") 
    {
        if (__helpZmain(cmd_.__getExec(), cmd_.__getStdd(), cmd_.__getPgOc())) {
            return true;
        }
    }

    return false;
}