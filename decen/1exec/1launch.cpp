#include "../utils-1exec.h"




// Function Definitions
bool __decen1exec_launch(Controller& cmd_) {
    if (cmd_.__getPgO() == "") {
        RunLauncher();
        return true;
    }

    return false;
}