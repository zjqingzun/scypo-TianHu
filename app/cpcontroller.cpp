// Library
#include "cpcontroller.h"




// Class definition
Controller::Controller() {
    _sto = "";
}

Controller::~Controller() {
    _sto = "";
}

void Controller::setString(std::string s) {
    _sto = s;
}

std::string Controller::getString() {
    return _sto;
}

void Controller::printString() {
    std::cout << _sto << std::endl;
}

void Controller::printString(std::string s) {
    std::cout << s << std::endl;
}

