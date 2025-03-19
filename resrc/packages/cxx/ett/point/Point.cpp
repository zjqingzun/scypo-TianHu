#include "Point.h"




// Function Definitions
// Contructor
double Point::__getX() {
    return _x;
}

double Point::__getY() {
    return _y;
}

void Point::__setX(double value) {
    _x = value;
}

void Point::__setY(double value) {
    _y = value;
}

Point::Point() {
    _x = 0;
    _y = 0;
}

void Point::__input() {
    std::cout << "Enter x: ";
    std::cin >> _x;
    std::cout << "Enter y: ";
    std::cin >> _y;
}

std::string Point::__toString() {
    std::ostringstream oss;
    oss << "(" << _x << ", " << _y << ")";
    return oss.str();
}