// Standard Template Library - STL C
#include "error.h"




// Function Definitions
void __printError(int errorCode) {
    // Init the file name
    char _fileName[20];
    snprintf(_fileName, sizeof(_fileName), "../../test/notification/error/%d.txt", errorCode);
    
    // Open the file
    FILE *file = fopen(_fileName, "r");
    if (file == NULL) {
        printf("Unknown error code: %d\n", errorCode);
        return;
    }
    
    // Print the error message
    char _line[256];
    while (fgets(_line, sizeof(_line), file)) {
        printf("%s", _line);
    }
    
    fclose(file);
}