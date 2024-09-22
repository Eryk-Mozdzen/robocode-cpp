#include <iostream>
#include <thread>
#include <chrono>

#include <robocode/Thread.h>
#include <robocode/Robot.h>

namespace robocode {

Robot::Robot() : thread{this, &Robot::loop} {
    std::cout << "Robot ctor" << std::endl;
}

Robot::~Robot() {
    std::cout << "Robot dtor" << std::endl;
}

void Robot::loop() {
    const auto start = std::chrono::high_resolution_clock::now();
    run();
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    if(duration<10) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10 - duration));
    }
}

Vector Robot::getPosition() const {
    return position;
}

Vector Robot::getVelocity() const {
    return velocity;
}

double Robot::getHealth() const {
    return health;
}

double Robot::getPower() const {
    return power;
}

void Robot::fire(const double strength) {
    queue.enqueue({FIRE, {strength}});
}

void Robot::setTracksVelocities(const double left, const double right) {
    queue.enqueue({VELOCITY, {left, right}});
}

}
