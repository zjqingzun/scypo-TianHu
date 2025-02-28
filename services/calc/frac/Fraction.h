#pragma once
#include <string>
#include <sstream>
#include <iostream>




// Fraction class
class Fraction {
private:
    int _num;
    int _den;
public:
    int getNumerator();
    int getDenominator();
    void setNumerator(int value);
    void setDenominator(int value);
public:
		Fraction();
public:
    void input();
    std::string toString();
};