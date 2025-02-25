#include "navigation.h"




// Function Definitions
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
        else {
            printf("\n");
            __printError(2);
        }
        printf("\n\n");
    }
}

