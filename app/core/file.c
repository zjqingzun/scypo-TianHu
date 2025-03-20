#include "file.h"




// Function Definitions
// Open a file
// The fopen() function is used to open a file. It returns a FILE* pointer
// fileName: The name of the file to open (including path if necessary)
// mode: File opening mode:
//      "r"     Read (file must exist)
//      "w"     Write (creates a new file or overwrites if it exists)
//      "a"     Append (adds to the end; creates if it doesn’t exist)
//      "r+"    Read and write (file must exist)
//      "w+"    Read and write (creates or overwrites)
//      "a+"    Read and append (creates if it doesn’t exist)
FILE* __fileOpen(const char* _fileName, const char* _mode) {
    FILE* _fp = fopen(_fileName, _mode);
    if (_fp == NULL) {
        printf("01:  !(app/core/file.c)\nCannot open file %s\n", _fileName);
    }
    return _fp;
}


// Close a file
// The fclose() function closes the file after operations are done
void __fileClose(FILE* _fp) {
    if (_fp != NULL) {
        fclose(_fp);
    }
}


// Write a data string to a file
void __fileWriteString(FILE* _fp, const char* _str) {
    if (_fp != NULL) {
        fprintf(_fp, "%s", _str);
    }
}


// Write a character data to a file
void __fileWriteCharacter(FILE* _fp, char _char) {
    if (_fp != NULL) {
        fputc(_char, _fp);
    }
}


// Read line by line from a file
void __fileReadByLine(FILE* _fp) {
    char _buffer[1024]; // Buffer to store each line
    if (_fp != NULL) {
        while (fgets(_buffer, sizeof(_buffer), _fp) != NULL) {
            printf("%s", _buffer); // Print the read line
        }
    }
}


// Read character by character from a file
void __fileReadByCharacter(FILE* _fp) {
    if (_fp != NULL) {
        int _char;
        while ((_char = fgetc(_fp)) != EOF) {
            putchar(_char); // Print the read character
        }
    }
}