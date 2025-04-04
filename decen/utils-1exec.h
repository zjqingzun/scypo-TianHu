#ifndef DECEN_UTILS_1EXEC_H
#define DECEN_UTILS_1EXEC_H
// config/src/ptog-import.json - D10001


// Decentralize
#include "utils-2stdd.h"




// Function Declarations
// C++
bool __decen1exec_contral(Controller& cmd_, int flags = 0);
bool __decen1exec_launch(Controller& cmd_);

// Python
void __decen1exec_callPython(const char* scriptName, const char* functionName);
bool __decen1exec_zerotask(Controller& cmd_);


#endif // DECEN_UTILS_1EXEC_H