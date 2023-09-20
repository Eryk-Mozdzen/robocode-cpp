#include <memory>
#include <iostream>

#include <robocode/Robot.h>

class ExampleBot : public robocode::Robot {
public:
    ExampleBot();
    ~ExampleBot();

    void run() override;
};

ExampleBot::ExampleBot() {
    std::cout << "ExampleBot ctor" << std::endl;
}

ExampleBot::~ExampleBot() {
    std::cout << "ExampleBot dtor" << std::endl;
}

void ExampleBot::run() {

}

extern "C" std::unique_ptr<robocode::Robot> create() {
    return std::make_unique<ExampleBot>();
}
