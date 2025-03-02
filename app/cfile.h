// STL - Standard Template Library for C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Build Library
#include "cerr.h"
#include "cchar.h"

// Constants
#define MAX_LINE_LENGTH 256


// Function: cfile_open
// Open a file for reading or writing.
// Functions Declarations
#ifndef FILE_H
#define FILE_H

#ifdef __cplusplus
extern "C" {
#endif

bool __checkStringInFile(const char* str);
int __checkMoMo(const char *momo);

#ifdef __cplusplus
}
#endif

#endif