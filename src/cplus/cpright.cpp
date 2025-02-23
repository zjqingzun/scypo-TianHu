// src/cplus/cpright.cpp
#include "cpright.h"

void __printCopyright() {
    system("cls");
    std::string _fileName = "docs/copyright.txt";

    std::ifstream file(_fileName);
    if (!file) {
        std::cerr << "Cannot open the file! " << _fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}
