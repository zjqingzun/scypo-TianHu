// STL - Standard Template Library for C++
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

// SCL - Supplementary Construction Library for C++
#include "../proc/coreprog.h"



// Function Declarations
// cpright.cpp
int __userCopyright();


// erno.cpp
int __erno__(const char* _errorCode);


// lang.cpp


// help.cpp
bool __helpZmain(std::string _exec, std::string _stdd, std::string _pack);
bool __helpZGet(std::string _stdd, std::string _pack);
bool __helpZGetPrint(const char* _filePath);
std::string readFile(const char* filename);
void printJsonItem(cJSON* item);
bool processAndPrintJson(const char* filename);

// launch.cpp


// frac.cpp


// zerotrace.cpp