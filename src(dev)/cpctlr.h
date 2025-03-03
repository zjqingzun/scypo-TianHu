// STL C++ Header file for controller.cpp
#ifndef CPCTLR_H
#define CPCTLR_H

#ifndef DISABLE_CPP_LIBS
#ifdef __cplusplus
#include <iostream>
#include <string>
#include <sstream>
#endif
#endif // DISABLE_CPP_LIBS


// Build Library
#include "cchar.h"
#include "cerr.h"
#ifndef DISABLE_CPP_LIBS
#include "cppmlib.h"
#endif



// Function Definitions
#ifdef __cplusplus
extern "C" {
#endif


void __normalMode(char* mode);
void __anlsMode(char* mode);
void __calcMode(char* mode);
void __taskMode(char* mode);


#ifdef __cplusplus
}
#endif
#endif // CPCTLR_H