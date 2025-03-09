#include <stdio.h>
#include <string.h>




// Define
#ifdef _WIN32
    #include <windows.h>
#else
    #include <strings.h> // For strcasecmp on Linux/macOS
#endif




// Function Declarations
void __setTextColor(const char* colorName);
void __resetColor();