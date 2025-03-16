#include "../../app/proc/ctl.h"




// main()
int main() {
    Controller controller_;
    std::string _input;

    std::cout << "The program splits the string into 9 parts." << std::endl;
    std::cout << "Please enter a string (up to 9 parts, separated by spaces):" << std::endl;
    std::cout << "Example: one two three four five six seven eight nine" << std::endl;

    // Get entire line including spaces
    std::getline(std::cin, _input);

    // Check if input is empty
    if(_input.empty()) {
        std::cout << "!(tests/proc/test-cli.cpp) Error: The input string must not be empty!" << std::endl;
        return 1;
    }

    // Process the input
    if (controller_.__splitString(_input)) {
        controller_.__displayParts();
    } else {
        std::cout << "!(tests/proc/test-cli.cpp) Error: The input string has too many parts!" << std::endl;
    }

    return 0;
}