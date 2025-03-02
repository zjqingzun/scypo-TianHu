#include <iostream>
using namespace std;

#include "Date.h"


int main() {
    Date d(2021, 1, 1);

    cout << d.getYear() << endl;
    cout << d.getMonth() << endl;
    cout << d.getDay() << endl;

    d.setYear(2022);
    d.setMonth(2);
    d.setDay(2);

    cout << d.getYear() << endl;
    cout << d.getMonth() << endl;
    cout << d.getDay() << endl;

    cout << "Date: "<< d.toString() << endl;

    return 0;
}