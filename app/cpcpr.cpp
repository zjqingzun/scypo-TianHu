// src/cplus/cpright.cpp
#include "cpcpr.h"




// Print the copy right
void __printCopyright() {
    // clear the screen
    system("cls");

    // init the file name
    std::string _fileName = "docs/copyright.txt";

    // open the file
    std::ifstream file(_fileName);
    if (!file) {
        __printError("FI000002", _fileName.c_str());
        std::cerr << _fileName << std::endl;
        return;
    }

    // print the file
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}
