#include "Fraction.h"



// Constructor
int Fraction::getNumerator() {
    return _num;
}

int Fraction::getDenominator() {
    return _den;
}

void Fraction::setNumerator(int value) {
    _num = value;
}

void Fraction::setDenominator(int value) {
    _den = value;
}

Fraction::Fraction() {
	_num = 0;
	_den = 1;
}

void Fraction::input() {
    std::cout << "Numerator:";
    std::cin >> _num;
    std::cout << "Denominator:";
    std::cin >> _den;
}

std::string Fraction::toString() {    
    std::stringstream builder;
    builder << _num << "/" << _den;
	return builder.str();
}