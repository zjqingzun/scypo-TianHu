// STL C++ Header file for controller.cpp
#ifdef __cplusplus
#include <iostream>
#include <string>
#endif



// Controller
#include "cpplib.h"




// Class definition
class Controller {
    private:
        std::string _sto;

    public:
        Controller();
        ~Controller();

    public:
        void setString(std::string);
        std::string getString();

    public:
        void printString();
        void printString(std::string);

};


