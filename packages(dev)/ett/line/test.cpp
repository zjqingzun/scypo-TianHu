#include <iostream>
using namespace std;

#include "Line.h"


int main()
{
    Line l1;
    l1.input();

    cout << "l1: " << l1.toString() << endl;

    return 0;
}