#include "cnavg.h"




// Function Definitions
// Navigation Pointer
void __navigationPointer() {
    // _inp is used to hold the user input and _dataLength is used to hold the length of the input
    char _inp[MAX_LEN] = {0};
    int _dataLength = 0;

    // Print the message
    while (1) {

        // Init the input and data length
        memset(_inp, 0, MAX_LEN);
        _dataLength = 0;


        // Get the user input
        printf(">>>>  ");
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
                        _inp[_dataLength] = '\0';
                        printf("\b \b");
                    }
                } 
                else if (_dataLength < MAX_LEN - 1) {
                    // Add the character to the input
                    _inp[_dataLength++] = character;
                    printf("%c", character);
                }
            }
        }

        // Add the null terminator
        _inp[_dataLength] = '\0';
        __removeTrailingChars(_inp);

        // Navigation Pointer
        char _navg[MAX_LEN] = {0};
        strcpy(_navg, _inp);

        // Controller
        // Check if the user wants to exit, clear the screen, or navigate to a controller
        if (strcmp(_navg, "exit") == 0) {
            break;
        }
        else if (strcmp(_navg, "clear") == 0) {
            system("cls");
        }
        else if (__checkStringInFile(_navg)) {
            // Controller
            // Mode of Operation
            char* momo = __getFirstWord(_navg);
            int mode = __checkMoMo(momo);

            // Check the mode of operation
            switch (mode)
            {
            case 0:
                // Normal Mode
                __normalMode(_navg);
                break;
            case 1:
                // Calculation Mode
                __calcMode(_navg);
                break;
            case 2:
                // Task Mode
                __taskMode(_navg);
                break;
            case 3:
                // Analysis Mode
                __anlsMode(_navg);
                break;
            default:
                break;
            }
        }        
        else {
            // Print the error message
            printf("\n");
            __printError("IN000001", _navg);
        }
        printf("\n");
    }
}

