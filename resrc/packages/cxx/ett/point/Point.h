#pragma once
#include <string>
#include <sstream>
#include <iostream>




// Class Declarations
class Point {
    private:
        double _x;
        double _y;
    
    public:
        double      __getX();
        double      __getY();
        void        __setX(double value);
        void        __setY(double value);

    public:
        Point();

    public:
        void        __input();
        std::string __toString();
};