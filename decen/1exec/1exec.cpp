#include "../utils-1exec.h"




// Function Definitions
bool __decen1exec_contral(Controller& cmd_, int flags) {
    if (flags == 0) {
        if (cmd_.__getExec() == "launch" && __decen1exec_launch(cmd_)) {
            return true;
        }
    }
    else if (flags == 2) {
        if (cmd_.__getExec() == "total" && __decen1exec_zerotask(cmd_)) {
            return true;   
        }
    }
    return false;
}