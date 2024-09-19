#pragma once

#include <memory>

#include <robocode/Thread.h>

#define ROBOCODE_REGISTER_ROBOT(name) \
    extern "C" std::unique_ptr<robocode::Robot> create() { \
        return std::make_unique<name>(); \
    }

namespace robocode {

class Robot {
    Thread<Robot> thread;

    friend class Engine;

public:
    Robot();
    virtual ~Robot();

    virtual void run() = 0;
};

}
