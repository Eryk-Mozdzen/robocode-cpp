#pragma once

#include <string>
#include <memory>

#include <robocode/Robot.h>

class RobotFactory {
    using Factory = std::unique_ptr<robocode::Robot> (*)();

    void *handle;
    Factory factory;

public:
    RobotFactory();
    RobotFactory(const std::string &path);
    ~RobotFactory();

    std::unique_ptr<robocode::Robot> create() const;
};
