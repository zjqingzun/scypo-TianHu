#include "user.h"




// Function Definitions
std::string __launchToLowerCase(const std::string& _str) {
    std::string _result = _str;
    for (char& _c : _result) {
        _c = tolower(_c);
    }
    return _result;
}