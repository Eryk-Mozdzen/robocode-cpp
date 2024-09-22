#include <iostream>

#include <robocode/Robot.h>

class ExampleBot : public robocode::Robot {
public:
    ExampleBot();
    ~ExampleBot();

    void run();
};

ExampleBot::ExampleBot() {
    std::cout << "ExampleBot ctor" << std::endl;
}

ExampleBot::~ExampleBot() {
    std::cout << "ExampleBot dtor" << std::endl;
}

void ExampleBot::run() {
    setTracksVelocities(1, 0.5);

    std::cout << "ExampleBot run " << getPosition() << std::endl;
}

ROBOCODE_REGISTER_ROBOT(ExampleBot)
