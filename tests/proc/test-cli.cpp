#include "../../app/proc/ctl.h"



int main() {
    Controller controller;
    std::string input;

    std::cout << "Chương trình phân tách chuỗi thành 9 phần" << std::endl;
    std::cout << "Vui lòng nhập một chuỗi (tối đa 9 phần, cách nhau bởi dấu cách):" << std::endl;
    std::cout << "Ví dụ: mot hai ba bon nam sau bay tam chin" << std::endl;

    // Get entire line including spaces
    std::getline(std::cin, input);

    // Check if input is empty
    if(input.empty()) {
        std::cout << "Lỗi: Chuỗi đầu vào không được để trống!" << std::endl;
        return 1;
    }

    // Process the input
    if (controller.splitString(input)) {
        controller.displayParts();
    } else {
        std::cout << "Lỗi: Chuỗi đầu vào có quá nhiều phần!" << std::endl;
    }

    return 0;
}