#include "../utils-1exec.h"




// Function Definitions
bool __decen1exec_zerotask(Controller& cmd_) {
    // Check if the command is valid
    if (cmd_.__getExec() == "") {

        // Zero the task

        return true;
    }

    return false;
}