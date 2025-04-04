#include "../utils-1exec.h"




// Function Definitions
bool __decen1exec_zerotask(Controller& cmd_) {
    // Check if the command is valid
    if (cmd_.__getPgO() == "") {

        // Zero the task
        __decen1exec_callPython("runtime", "__taskRun");

        return true;
    }

    return false;
}