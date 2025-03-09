#include "../../app/core/gui.h"




int main() {
    __setTextColor("red");
    printf("This is red text\n");
    __resetColor();

    __setTextColor("green");
    printf("This is green text\n");
    __resetColor();

    __setTextColor("blue");
    printf("This is blue text\n");
    __resetColor();

    return 0;
}