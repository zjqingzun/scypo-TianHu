#include "../../app/core/gui.h"




// main()
int main() {
    // Set text color to red
    __setTextColor("red");
    printf("This is red text\n");
    __resetColor();

    // Set text color to green
    __setTextColor("green");
    printf("This is green text\n");
    __resetColor();

    // Set text color to blue 
    __setTextColor("blue");
    printf("This is blue text\n");
    __resetColor();

    return 0;
}