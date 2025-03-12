#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <iostream>
#include <sstream>



// Class
class Controller {
private:
    std::string part1, part2, part3, part4, part5, part6, part7, part8, part9;
    static const int EXPECTED_PARTS = 9;

public:
    // Constructors
    Controller();
    Controller(const std::string& p1, const std::string& p2, const std::string& p3,
              const std::string& p4, const std::string& p5, const std::string& p6,
              const std::string& p7, const std::string& p8, const std::string& p9);

    // Destructor
    ~Controller();

    // Split string method
    bool splitString(const std::string& input);

    // Getters
    std::string getPart1() const { return part1; }
    std::string getPart2() const { return part2; }
    std::string getPart3() const { return part3; }
    std::string getPart4() const { return part4; }
    std::string getPart5() const { return part5; }
    std::string getPart6() const { return part6; }
    std::string getPart7() const { return part7; }
    std::string getPart8() const { return part8; }
    std::string getPart9() const { return part9; }

    // Setters
    void setPart1(const std::string& value) { part1 = value; }
    void setPart2(const std::string& value) { part2 = value; }
    void setPart3(const std::string& value) { part3 = value; }
    void setPart4(const std::string& value) { part4 = value; }
    void setPart5(const std::string& value) { part5 = value; }
    void setPart6(const std::string& value) { part6 = value; }
    void setPart7(const std::string& value) { part7 = value; }
    void setPart8(const std::string& value) { part8 = value; }
    void setPart9(const std::string& value) { part9 = value; }

    // Display method
    void displayParts() const;
};

#endif