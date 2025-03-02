// Standard Template Library - STL C
#include "cerr.h"




// Function Definitions
// Print the error message
void __printError(const char *errorCode, const char *errorMessage) {
    // open the file
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

        // check the error code
        if (token) {
            __trimWhitespace(token);
            if (strcmp(token, errorCode) == 0) {
                // get the error message
                char *message = strtok(NULL, "|");

                // print the error message
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