// STL - Standard Template Library C
#include <stdio.h>
#include <string.h>
#include <ctype.h>




// Function Declarations
#ifndef CHARACTER_H
#define CHARACTER_H

#ifdef __cplusplus
extern "C" {
#endif

void __removeTrailingChars(char *str);
void __removeLeadingSpaces(char *str);
void __trimWhitespace(char *str);
char* __getFirstWord(const char *_str);

#ifdef __cplusplus
}
#endif

#endif