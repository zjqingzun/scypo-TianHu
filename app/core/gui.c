#include "gui.h"




// Function Definitions
// Function to set text color based on color name
void __setTextColor(const char* _colorName) {
    #ifdef _WIN32
        HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int _color = 7; // Default to light gray (white-ish)
    
        if      (_stricmp(_colorName, "black")   == 0) _color = 0;
        else if (_stricmp(_colorName, "red")     == 0) _color = FOREGROUND_RED;
        else if (_stricmp(_colorName, "green")   == 0) _color = FOREGROUND_GREEN;
        else if (_stricmp(_colorName, "yellow")  == 0) _color = FOREGROUND_RED | FOREGROUND_GREEN;
        else if (_stricmp(_colorName, "blue")    == 0) _color = FOREGROUND_BLUE;
        else if (_stricmp(_colorName, "magenta") == 0) _color = FOREGROUND_RED | FOREGROUND_BLUE;
        else if (_stricmp(_colorName, "cyan")    == 0) _color = FOREGROUND_GREEN | FOREGROUND_BLUE;
        else if (_stricmp(_colorName, "white")   == 0) _color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    
        SetConsoleTextAttribute(_hConsole, _color);
    #else
        const char* _ansiColor = "\033[37m"; // Default to white
    
        if      (strcasecmp(_colorName, "black")   == 0) _ansiColor = "\033[30m";
        else if (strcasecmp(_colorName, "red")     == 0) _ansiColor = "\033[31m";
        else if (strcasecmp(_colorName, "green")   == 0) _ansiColor = "\033[32m";
        else if (strcasecmp(_colorName, "yellow")  == 0) _ansiColor = "\033[33m";
        else if (strcasecmp(_colorName, "blue")    == 0) _ansiColor = "\033[34m";
        else if (strcasecmp(_colorName, "magenta") == 0) _ansiColor = "\033[35m";
        else if (strcasecmp(_colorName, "cyan")    == 0) _ansiColor = "\033[36m";
        else if (strcasecmp(_colorName, "white")   == 0) _ansiColor = "\033[37m";
    
        printf("%s", _ansiColor);
    #endif
}


// Function to reset text color to default
void __resetColor() {
    #ifdef _WIN32
        HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(_hConsole, 7); // Default to light gray
    #else
        printf("\033[0m");
    #endif
}
    
    