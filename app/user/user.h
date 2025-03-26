#ifndef USER_H
#define USER_H
// config/src/prog-import.json - AU0002

// SCL - Supplementary Construction Library for C++
#include "../proc/coreprog.h"
#include "utils.h"
#include <iomanip>
//#include "type.h"

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
std::string __helpZReadFile(const char* _fileName);
void __helpZPrintJsonItem(cJSON* _item);
bool __helpZProcessAndPrintJson(const char* _fileName);

// launch.cpp
#include "launch.h"


// frac.cpp


// zerotrace.cpp


#endif // USER_H