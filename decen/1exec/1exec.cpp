#include "../utils-1exec.h"




// Function Definitions
bool __decen1exec_contral(Controller& cmd_) {
    if (cmd_.__getExec() == "launch" && __decen1exec_launch(cmd_)) {
        return true;
    }

    return false;
}