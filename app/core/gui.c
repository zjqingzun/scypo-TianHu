#include "gui.h"




// Function Definitions
// Function to set text color based on color name
void __setTextColor(const char* colorName) {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int color = 7; // Default to light gray (white-ish)
    
        if (_stricmp(colorName, "black") == 0) color = 0;
        else if (_stricmp(colorName, "red") == 0) color = FOREGROUND_RED;
        else if (_stricmp(colorName, "green") == 0) color = FOREGROUND_GREEN;
        else if (_stricmp(colorName, "yellow") == 0) color = FOREGROUND_RED | FOREGROUND_GREEN;
        else if (_stricmp(colorName, "blue") == 0) color = FOREGROUND_BLUE;
        else if (_stricmp(colorName, "magenta") == 0) color = FOREGROUND_RED | FOREGROUND_BLUE;
        else if (_stricmp(colorName, "cyan") == 0) color = FOREGROUND_GREEN | FOREGROUND_BLUE;
        else if (_stricmp(colorName, "white") == 0) color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    
        SetConsoleTextAttribute(hConsole, color);
    #else
        const char* ansiColor = "\033[37m"; // Default to white
    
        if (strcasecmp(colorName, "black") == 0) ansiColor = "\033[30m";
        else if (strcasecmp(colorName, "red") == 0) ansiColor = "\033[31m";
        else if (strcasecmp(colorName, "green") == 0) ansiColor = "\033[32m";
        else if (strcasecmp(colorName, "yellow") == 0) ansiColor = "\033[33m";
        else if (strcasecmp(colorName, "blue") == 0) ansiColor = "\033[34m";
        else if (strcasecmp(colorName, "magenta") == 0) ansiColor = "\033[35m";
        else if (strcasecmp(colorName, "cyan") == 0) ansiColor = "\033[36m";
        else if (strcasecmp(colorName, "white") == 0) ansiColor = "\033[37m";
    
        printf("%s", ansiColor);
    #endif
}


// Function to reset text color to default
void __resetColor() {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 7); // Default to light gray
    #else
        printf("\033[0m");
    #endif
}
    
    