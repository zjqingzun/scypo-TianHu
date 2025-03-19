#pragma once
#include <string>
#include <sstream>
#include <iostream>




// Class Declarations
class Fraction {
    private:
        int _num;
        int _den;

    public:
        int         __getNumerator();
        int         __getDenominator();
        void        __setNumerator(int value);
        void        __setDenominator(int value);

    public:
	    Fraction();

    public:
        void        __input();
        std::string __toString();
};