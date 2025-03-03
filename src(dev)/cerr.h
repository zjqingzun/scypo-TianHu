// Standard Template Library - STL C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Build Library
#include "cchar.h"



// Constants
#define MAX_LINE_LENGTH 256




// Function Declarations
#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

void __printError(const char *errorCode, const char *errorMessage);

#ifdef __cplusplus
}
#endif

#endif
