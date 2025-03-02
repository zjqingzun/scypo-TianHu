#include "cchar.h"




// Function Definitions
// Remove Trailing Characters
void __removeTrailingChars(char *str) {
    char *_handl = str + strlen(str) - 1;
    
    while (_handl >= str && (*_handl == '\n' || *_handl == ' ')) {
        *_handl = '\0';
        _handl--;
    }
}


// Remove the leading spaces
void __removeLeadingSpaces(char *str) {
    // i is used to iterate the string and j is used to hold the position of the string
    int i = 0, j = 0;

    // remove the leading spaces
    while (isspace((unsigned char)str[i])) {
        i++;
    }

    // shift the string
    while (str[i] != '\0') {
        str[j] = str[i];
        i++;
        j++;
    }
    str[j] = '\0';
}


// Trim the whitespace
void __trimWhitespace(char *str) {
    // _prog is used to hold the position of the string
    char *_prog;

    // if the string is empty
    while (*str == ' ') str++;
    if (*str == 0) return;
    
    // handle the string
    _prog = str + strlen(str) - 1;
    while (_prog > str && (*_prog == ' ' || *_prog == '\n' || *_prog == '\r')) _prog--;
    *(_prog + 1) = '\0';
}


// Get the first word
char* __getFirstWord(const char *_str) {
    // _result is used to hold the result and _ptr is used to hold the pointer
    static char _result[100];
    char *_ptr = _result;
    
    // get the first word
    while (*_str == ' ') _str++;
    while (*_str && *_str != ' ') {
        *_ptr++ = *_str++;
    }

    // add the null terminator and return the result
    *_ptr = '\0';
    return _result;
}