#pragma once

#include <vector>
#include <memory>

#include <robocode/Robot.h>
#include <robocode/RobotFactory.h>

namespace robocode {

class Engine {
    std::vector<std::unique_ptr<Robot>> robots;

public:
    Engine(const std::vector<RobotFactory> &factories);
    ~Engine();
};

}