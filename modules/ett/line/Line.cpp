#include "Line.h"




// Contructor
Point Line::getP1() {
    return p1;
}

Point Line::getP2() {
    return p2;
}

void Line::setP1(Point value) {
    p1 = value;
}

void Line::setP2(Point value) {
    p2 = value;
}

Line::Line() {
    p1 = Point();
    p2 = Point();
}

void Line::input() {
    std::cout << "Enter p1: ";
    p1.input();
    std::cout << "Enter p2: ";
    p2.input();
}

std::string Line::toString() {
    std::stringstream ss;
    ss << "Line(" << p1.toString() << ", " << p2.toString() << ")";
    return ss.str();
}


