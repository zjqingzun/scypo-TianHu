#include "ctl.h"




//// Function Definitions
// Constructor
// Default constructor
Controller::Controller() :
    _pgO(""), _type(""), _momo(""), _exec(""), _stdd(""), _pgOc(""), _status(""), _digit(""), _info("") {
    _part = 0;
}

// Parameterized constructor
Controller::Controller(const std::string& str01, const std::string& str02, const std::string& str03, const std::string& str04, 
    const std::string& str05, const std::string& str06, const std::string& str07) :
    _momo(str01), _exec(str02), _stdd(str03), _pgOc(str04), _status(str05), _digit(str06), _info(str07) {
    _part = 0;
}

Controller::Controller(const std::string& str01, const std::string& str02, const std::string& str03, const std::string& str04, 
    const std::string& str05, const std::string& str06, const std::string& str07, const std::string& str08, const std::string str09) :
    _pgO(str01), _type(str02), _momo(str03), _exec(str04), _stdd(str05), _pgOc(str06), _status(str07), _digit(str08), _info(str09) {
    _part = 0;
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


    // Split the string by spaces
    while (iss >> part) {
        if (currentPart > _MAXCOUNT) {
            return false; // Too many parts
        }
        switch(currentPart) {
            case 1: _pgO    = part; break;
            case 2: _type   = part; break;
            case 3: _momo   = part; break;
            case 4: _exec   = part; break;
            case 5: _stdd   = part; break;
            case 6: _pgOc   = part; break;
            case 7: _status = part; break;
            case 8: _digit  = part; break;
            case 9: _info   = part; break;
        }
        _part++;
        currentPart++;
    }

    return true;
}

// CLICMD
void Controller::__CommandCLI() {

    // For special fields, ! disables the special field, and = enables the special field
    if (_part == 1)
    {
        __setMomo(__getPgO());
        __setPgO("");   // Reset
    }
    else if (_part == 2)
    {
        __setExec(__getType());
        __setMomo(__getPgO());
        __setType("");  // Reset
        __setPgO("");   // Reset
    }
    else if (_part == 3)
    {
        if (_momo.find('-', 0) != 0) 
        {
            __setPgOc(__getMomo());
            __setExec(__getType());
            __setMomo(__getPgO());
            __setType("");  // Reset
            __setPgO("");   // Reset
        }
        else
        {
            __setStdd(__getMomo());
            __setExec(__getType());
            __setMomo(__getPgO());
            __setType("");  // Reset
            __setPgO("");   // Reset
        }
    }
    else if (_part == 4)
    {
        if (_type.find('-', 0) != 0)
        {
            if (_momo.find('-', 0) == 0) 
            {
                __setPgOc(__getExec());
                __setStdd(__getMomo());
                __setExec(__getType());
                __setMomo(__getPgO());
                __setType("");  // Reset
                __setPgO("");   // Reset
            }
            else 
            {
                if (_exec.find('@', 0) == 0)
                {
                    __setStatus(__getExec());
                    __setPgOc(__getMomo());
                    __setExec(__getType());
                    __setMomo(__getPgO());
                    __setType("");  // Reset
                    __setPgO("");   // Reset
                }
                else
                {
                    __setDigit(__getExec());
                    __setPgOc(__getMomo());
                    __setExec(__getType());
                    __setMomo(__getPgO());
                    __setType("");  // Reset
                    __setPgO("");   // Reset
               }
            }
        }
    }
    // Continue......................
}



// Display method
void Controller::__displayParts() const {
    std::cout << "List  -   Part: \""<< _part   << "\"" << std::endl;
    
    std::cout << "PackageO: \""      << _pgO    << "\"" << std::endl;
    std::cout << "Type: \""          << _type   << "\"" << std::endl;
    std::cout << "Mode - Module: \"" << _momo   << "\"" << std::endl;
    std::cout << "Execute: \""       << _exec   << "\"" << std::endl;
    std::cout << "Standard: \""      << _stdd   << "\"" << std::endl;
    std::cout << "Package: \""       << _pgOc   << "\"" << std::endl;
    std::cout << "Status: \""        << _status << "\"" << std::endl;
    std::cout << "Digit: \""         << _digit  << "\"" << std::endl;
    std::cout << "Info: \""          << _info   << "\"" << std::endl;
}