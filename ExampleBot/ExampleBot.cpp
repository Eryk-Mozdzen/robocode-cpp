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
    std::cout << "ExampleBot run" << std::endl;
}

ROBOCODE_REGISTER_ROBOT(ExampleBot)
