#include "cnavigation.h"




// Function Definitions
// Check if the string is mode, module, or controller
bool __checkStringInFile(const char* str) {
    const char* _fileName = "docs/mode.txt";
    FILE *file = fopen(_fileName, "r");
    if (file == NULL) {
        __printError("IN000002", _fileName);
        return false;
    }

    char line[1024];
    bool found = false;

    while (fgets(line, sizeof(line), file) != NULL) {
        // line[strcspn(line, "\n")] = 0;
        if (strstr(line, str) != NULL) {
            found = true;
            break;
        }
    }

    fclose(file);
    return found;
}


// Navigation Pointer
void __navigationPointer() {
    char _navigationPointer[MAX_LEN] = {0};
    int _dataLength = 0;

    // Print the message
    while (1) {

        // Init the navigation pointer
        memset(_navigationPointer, 0, MAX_LEN);
        _dataLength = 0;
        printf(">>>>  ");


        // Get the user input
        while (1) {
            if (_kbhit()) {
                // Get the character
                char character = _getch();
    
                // Check if the character is a return or enter key
                if (character == '\r') {
                    break;
                } 
                else if (character == 8) {
                    // Check if the data length is greater than 0
                    if (_dataLength > 0) {
                        _dataLength--;
                        _navigationPointer[_dataLength] = '\0';
                        printf("\b \b");
                    }
                } 
                else if (_dataLength < MAX_LEN - 1) {
                    // Add the character to the navigation pointer
                    _navigationPointer[_dataLength++] = character;
                    printf("%c", character);
                }
            }
        }

        // Add the null terminator
        _navigationPointer[_dataLength] = '\0';


        // Check if the user wants to exit
        if (strcmp(_navigationPointer, "exit") == 0) {
            break;
        }
        else if (strcmp(_navigationPointer, "clear") == 0) {
            system("cls");
        }
        else if (__checkStringInFile(_navigationPointer)) {
            // Controller
        }
        else {
            printf("\n");
            __printError("IN000001", _navigationPointer);
        }


        printf("\n\n");
    }
}

