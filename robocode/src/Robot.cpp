#include <iostream>

#include <robocode/Robot.h>

namespace robocode {

Robot::Robot() {
    std::cout << "Robot ctor" << std::endl;
}

Robot::~Robot() {
    std::cout << "Robot dtor" << std::endl;
}

Robot::State Robot::getState() const {
    return State();
}

}
