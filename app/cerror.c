// Standard Template Library - STL C
#include "cerror.h"




// Function Definitions
// Remove the leading spaces
void __removeLeadingSpaces(char *str) {
    int i = 0, j = 0;

    // Remove the leading spaces
    while (isspace((unsigned char)str[i])) {
        i++;
    }

    // Shift the string
    while (str[i] != '\0') {
        str[j] = str[i];
        i++;
        j++;
    }
    str[j] = '\0';
}


// Trim the whitespace
void __trimWhitespace(char *str) {
    char *_prog;
    while (*str == ' ') str++;
    if (*str == 0) return;
    _prog = str + strlen(str) - 1;
    while (_prog > str && (*_prog == ' ' || *_prog == '\n' || *_prog == '\r')) _prog--;
    *(_prog + 1) = '\0';
}


// Print the error message
void __printError(const char *errorCode, const char *errorMessage) {
    // Open the file
    const char *_fileName = "resrc/erno/ERNO.scy";
    FILE *_file = fopen(_fileName, "r");
    if (!_file) {
        perror("Undefined error.\n");
        return;
    }


    // Print the error message
    char _line[MAX_LINE_LENGTH];
    while (fgets(_line, sizeof(_line), _file)) {
        char *token = strtok(_line, "|");


        // Check the error code
        if (token) {
            __trimWhitespace(token);
            if (strcmp(token, errorCode) == 0) {
                char *message = strtok(NULL, "|");

                // Print the error message
                if (message) {
                    __trimWhitespace(message);
                    __removeLeadingSpaces(message);
                    printf("%s: '%s' %s\n", errorMessage, errorMessage, message);
                } else {
                    printf("Underfined error.\n");
                }
                fclose(_file);
                return;
            }
        }
    }

    printf("Underfined error.\n");
    fclose(_file);
}