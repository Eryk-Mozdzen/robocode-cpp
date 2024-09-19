#pragma once

#include <string>
#include <memory>

#include <robocode/Robot.h>

namespace robocode {

class RobotFactory {
    using Factory = std::unique_ptr<robocode::Robot> (*)();

    void *handle;
    Factory factory;

public:
    RobotFactory(const std::string &path);
    RobotFactory(const RobotFactory &) = delete;
    RobotFactory(RobotFactory &&other);
    ~RobotFactory();

    RobotFactory &operator=(const RobotFactory &) = delete;
    RobotFactory & operator=(RobotFactory &&other);

    std::unique_ptr<robocode::Robot> create() const;
};

}
