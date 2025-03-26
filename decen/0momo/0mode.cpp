#include "../utils-0momo.h"




// Function Definitions
bool __decen0momo_mode(Controller& cmd_) {
    if (cmd_.__getMomo() == "norm" || cmd_.__getMomo() == "calc" || cmd_.__getMomo() == "task" || cmd_.__getMomo() == "anls") {
        if (__decen1exec_contral(cmd_)) {
            return true;
        }
    }
    return false;
}