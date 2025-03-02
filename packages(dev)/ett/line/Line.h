#pragma once
#include <string>
#include <sstream>
#include <iostream>


#include "../point/Point.h"




// Fraction class
class Line {
    private:
        Point p1;
        Point p2;
    public:
        Point getP1();
        Point getP2();
        void setP1(Point value);
        void setP2(Point value);
    public:
        Line();
    public:
        void input();
        std::string toString();
};