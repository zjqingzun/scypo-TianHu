#pragma once
#include <string>
#include <sstream>
#include <iostream>




// Fraction class
class Point {
private:
    double _x;
    double _y;
public:
    double getX();
    double getY();
    void setX(double value);
    void setY(double value);
public:
    Point();
public:
    void input();
    std::string toString();
};