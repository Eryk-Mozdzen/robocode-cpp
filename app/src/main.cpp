#include <map>
#include <vector>
#include <memory>

#include <robocode/Robot.h>
#include "RobotFactory.h"

int main() {
    std::map<std::string, RobotFactory> factories;
    factories.insert(std::make_pair("ExampleBot", "../../ExampleBot/build/ExampleBot.so"));

    std::vector<std::unique_ptr<robocode::Robot>> robots;
    robots.push_back(factories["ExampleBot"].create());
}
