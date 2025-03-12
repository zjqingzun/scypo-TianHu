#include "ctl.h"




//// Function Definitions
// Constructor
// Default constructor
Controller::Controller() :
    _pgO(""), _type(""), _momo(""), _exec(""), _stdd(""), _pgOc(""), _status(""), _digit(""), _info("") {

}

// Parameterized constructor
Controller::Controller(const std::string& str01, const std::string& str02, const std::string& str03, const std::string& str04, 
    const std::string& str05, const std::string& str06, const std::string& str07) :
    _momo(str01), _exec(str02), _stdd(str03), _pgOc(str04), _status(str05), _digit(str06), _info(str07) {

}

Controller::Controller(const std::string& str01, const std::string& str02, const std::string& str03, const std::string& str04, 
    const std::string& str05, const std::string& str06, const std::string& str07, const std::string& str08, const std::string str09) :
    _pgO(str01), _type(str02), _momo(str03), _exec(str04), _stdd(str05), _pgOc(str06), _status(str07), _digit(str08), _info(str09) {

}


// Destructor
Controller::~Controller() {
    // Clean up if needed
}


// Split string method
bool Controller::__splitString(std::string& input) {
    // Reset all parts
    _pgO = _type = _momo = _exec = _stdd = _pgOc = _status = _digit = _info = "";

    
    std::istringstream iss(input);
    std::string part;
    int currentPart = 1;

    return true;
}