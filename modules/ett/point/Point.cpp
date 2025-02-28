#include "Point.h"




// Contructor
double Point::getX() {
    return _x;
}

double Point::getY() {
    return _y;
}

void Point::setX(double value) {
    _x = value;
}

void Point::setY(double value) {
    _y = value;
}

Point::Point() {
    _x = 0;
    _y = 0;
}

void Point::input() {
    std::cout << "Enter x: ";
    std::cin >> _x;
    std::cout << "Enter y: ";
    std::cin >> _y;
}

std::string Point::toString() {
    std::ostringstream oss;
    oss << "(" << _x << ", " << _y << ")";
    return oss.str();
}