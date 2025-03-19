#include "Fraction.h"




// Function Definitions
// Constructor
int Fraction::__getNumerator() {
    return _num;
}

int Fraction::__getDenominator() {
    return _den;
}

void Fraction::__setNumerator(int value) {
    _num = value;
}

void Fraction::__setDenominator(int value) {
    _den = value;
}

Fraction::Fraction() {
	_num = 0;
	_den = 1;
}

void Fraction::__input() {
    std::cout << "Numerator:";
    std::cin >> _num;
    std::cout << "Denominator:";
    std::cin >> _den;
}

std::string Fraction::__toString() {    
    std::stringstream builder;
    builder << _num << "/" << _den;
	return builder.str();
}