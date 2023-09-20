#pragma once

namespace robocode {

class Robot {
public:
    Robot();
    virtual ~Robot();

    virtual void run() = 0;

    float getX() const;
    float getY() const;
};

}
