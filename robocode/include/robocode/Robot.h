#pragma once

#include <memory>

#include <robocode/Thread.h>
#include <robocode/Vector.h>
#include <robocode/Queue.h>

#define ROBOCODE_REGISTER_ROBOT(name) \
    extern "C" std::unique_ptr<robocode::Robot> create() { \
        return std::make_unique<name>(); \
    }

namespace robocode {

class Robot {
    enum CommandId {
        FIRE,
        VELOCITY,
    };

    struct Command {
        CommandId id;
        std::vector<double> args;
    };

    Vector position = {0, 0};
    Vector velocity = {0, 0};
    double orientation = 0;
    double angularVelocity = 0;
    double health = 100;
    double power = 20;

    Thread<Robot> thread;
    Queue<Command> queue;

    friend class Engine;

    void loop();

protected:
    Vector getPosition() const;
    Vector getVelocity() const;
    double getHealth() const;
    double getPower() const;

    void fire(const double strength);
    void setTracksVelocities(const double left, const double right);

public:
    Robot();
    virtual ~Robot();

    virtual void run() = 0;
};

}
