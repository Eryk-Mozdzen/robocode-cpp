#include <iostream>

#include <robocode/Robot.h>

namespace robocode {

Robot::Robot() {
    std::cout << "Robot ctor" << std::endl;
}

Robot::~Robot() {
    std::cout << "Robot dtor" << std::endl;
}

float Robot::getX() const {
    return 0;
}

float Robot::getY() const {
    return 0;
}

}
