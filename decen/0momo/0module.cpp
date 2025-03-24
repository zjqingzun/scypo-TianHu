#include "../utils-0momo.h"




// Function Definitions
bool __decen0module(Controller& cmd_) {
    if (cmd_.__getMomo() == "help" || cmd_.__getMomo() == "-h") 
    {
        if (__helpZmain(cmd_.__getExec(), cmd_.__getStdd(), cmd_.__getPgOc())) {
            return true;
        }
    }
    else if (cmd_.__getMomo() == "launch")
    {
        RunLauncher();
        return true;
    }

    return false;
}