#include "cfile.h"




// Function Definitions
// Check if the string is mode, module, or controller
bool __checkStringInFile(const char* str) {
    // open the file for reading the modes
    const char* _fileName = "docs/modules.txt";
    FILE *_file = fopen(_fileName, "r");
    if (_file == NULL) {
        __printError("IN000002", _fileName);
        return false;
    }

    // initialize the line buffer
    char _line[1024];
    bool _found = false;

    // check if the string is in the file
    while (fgets(_line, sizeof(_line), _file) != NULL) {
        // line[strcspn(line, "\n")] = 0;
        if (strstr(_line, str) != NULL) {
            _found = true;
            break;
        }
    }

    fclose(_file);
    return _found;
}


int __checkMoMo(const char *momo) {
    const char *_filename = "docs/mode.txt";
    FILE *file = fopen(_filename, "r");
    if (file == NULL) {
        __printError("IN000002", _filename);
        return -1;
    }
    
    char _line[MAX_LINE_LENGTH];
    int _lineNumber = 0;
    while (fgets(_line, sizeof(_line), file)) {
        _lineNumber++;
        _line[strcspn(_line, "\n")] = 0;
        
        if (strcmp(_line, momo) == 0) {
            fclose(file);
            return _lineNumber;
        }
    }
    
    fclose(file);
    return 0;
}