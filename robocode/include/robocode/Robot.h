#pragma once

#include <robocode/Vector.h>

namespace robocode {

class Robot {
public:
    struct State {
        Vector position;
        float gunPosition;
        float radarPosition;
    };

    Robot();
    virtual ~Robot();

    virtual void run() = 0;

    State getState() const;

private:
    State state;
};

}
