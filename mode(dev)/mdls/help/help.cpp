#include "help.h"




// Header
void __guideFile() {
    // init the file name
    std::string _fileName = "docs/guide.txt";

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




// Handle
void __guideModule(std::string str) {
    std::cout << "\n\n";

    __guideFile();

    std::cout << "\n\n" << "LIST:" << "\n";
}


void __guideMode() {
    std::cout << "\n\n";

    __guideFile();

    std::cout << "\n\n" << "LIST:" << "\n";
}