#include <iostream>

#include <robocode/Thread.h>
#include <robocode/Robot.h>

namespace robocode {

Robot::Robot() : thread{this, &Robot::run} {
    std::cout << "Robot ctor" << std::endl;
}

Robot::~Robot() {
    std::cout << "Robot dtor" << std::endl;
}

}
