#include "ctl.h"




// Default constructor
Controller::Controller() : 
    part1(""), part2(""), part3(""), part4(""), part5(""),
    part6(""), part7(""), part8(""), part9("") {
}

// Parameterized constructor
Controller::Controller(const std::string& p1, const std::string& p2, const std::string& p3,
                     const std::string& p4, const std::string& p5, const std::string& p6,
                     const std::string& p7, const std::string& p8, const std::string& p9) :
    part1(p1), part2(p2), part3(p3), part4(p4), part5(p5),
    part6(p6), part7(p7), part8(p8), part9(p9) {
}

// Destructor
Controller::~Controller() {
    // Clean up if needed
}

bool Controller::splitString(const std::string& input) {
    // Reset all parts
    part1 = part2 = part3 = part4 = part5 = part6 = part7 = part8 = part9 = "";

    std::istringstream iss(input);
    std::string part;
    int currentPart = 1;

    // Split the string by spaces
    while (iss >> part) {
        if (currentPart > EXPECTED_PARTS) {
            return false; // Too many parts
        }
        switch(currentPart) {
            case 1: part1 = part; break;
            case 2: part2 = part; break;
            case 3: part3 = part; break;
            case 4: part4 = part; break;
            case 5: part5 = part; break;
            case 6: part6 = part; break;
            case 7: part7 = part; break;
            case 8: part8 = part; break;
            case 9: part9 = part; break;
        }
        currentPart++;
    }

    return true;
}

void Controller::displayParts() const {
    std::cout << "Các phần sau khi phân tách:" << std::endl;
    std::cout << "Phần 1: \"" << part1 << "\"" << std::endl;
    std::cout << "Phần 2: \"" << part2 << "\"" << std::endl;
    std::cout << "Phần 3: \"" << part3 << "\"" << std::endl;
    std::cout << "Phần 4: \"" << part4 << "\"" << std::endl;
    std::cout << "Phần 5: \"" << part5 << "\"" << std::endl;
    std::cout << "Phần 6: \"" << part6 << "\"" << std::endl;
    std::cout << "Phần 7: \"" << part7 << "\"" << std::endl;
    std::cout << "Phần 8: \"" << part8 << "\"" << std::endl;
    std::cout << "Phần 9: \"" << part9 << "\"" << std::endl;
}