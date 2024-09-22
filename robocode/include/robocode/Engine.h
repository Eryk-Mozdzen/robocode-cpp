#pragma once

#include <vector>
#include <memory>

#include <robocode/Thread.h>
#include <robocode/Robot.h>
#include <robocode/RobotFactory.h>

namespace robocode {

class Engine {
    Thread<Engine> thread;
    std::vector<std::unique_ptr<Robot>> robots;

    void loop();

public:
    Engine(const std::vector<RobotFactory> &factories);
    ~Engine();

    bool isBattleInProgress() const;
};

}
