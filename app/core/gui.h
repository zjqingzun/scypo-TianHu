// include <gui-interface.h>
#ifndef GUI_H
#define GUI_H
// config/src/prog-import.json - AC0006

#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


// Define
#ifdef _WIN32
    #include <windows.h>
#else
    #include <strings.h> // For strcasecmp on Linux/macOS
#endif


// Function Declarations
void __setTextColor(const char* _colorName);
void __resetColor();


#ifdef __cplusplus
}
#endif

#endif