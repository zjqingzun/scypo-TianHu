#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../lib/cJSON.h"




#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif


// Function Declarations
// Function to load error messages from a JSON file
cJSON *__loadErrorMessages(const char *_filePath);
// Function to retrieve and print error message based on error code
void __getErrorMessage(const char *_errorCode, cJSON *_errorData);


#ifdef __cplusplus
}
#endif

#endif