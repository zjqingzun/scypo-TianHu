#include <iostream>
using namespace std;

#include "Point.h"

int main() {

    Point p1;
    
    cout << "Nhap vao mot diem." << endl;
    p1.input();

    cout << "Diem vua nhap la: ";
    cout << p1.toString() << endl;

    return 0;
}