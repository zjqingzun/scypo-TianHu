#include <iostream>
using namespace std;


#include "../mode/services/calc/frac/Fraction.h"




// Test case 1
int main()
{
    cout << "Nhap xuat so nguyen" << endl << endl;
    
    cout << "Nhap vao mot phan so." << endl;
    Fraction a;
    a.input();
    
    cout << "Phan so vua nhap la:";
    cout << a.toString();
}