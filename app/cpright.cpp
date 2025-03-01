// src/cplus/cpright.cpp
#include "cpright.h"




// Print the copy right
void __printCopyright() {
    // Clear the screen
    system("cls");

    // Init the file name
    std::string _fileName = "docs/copyright.txt";

    // Open the file
    std::ifstream file(_fileName);
    if (!file) {
        __printError("FI000002", _fileName.c_str());
        std::cerr << _fileName << std::endl;
        return;
    }

    // Print the file
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}
