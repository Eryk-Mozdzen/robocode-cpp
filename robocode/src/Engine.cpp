#include <vector>
#include <memory>
#include <utility>

#include <robocode/Engine.h>
#include <robocode/Robot.h>
#include <robocode/RobotFactory.h>

namespace robocode {

Engine::Engine(const std::vector<RobotFactory> &factories) {
    for(const RobotFactory &factory : factories) {
        robots.push_back(factory.create());
    }

    for(auto &robot : robots) {
        robot->thread.start();
    }
}

Engine::~Engine() {
    for(auto &robot : robots) {
        robot->thread.stop();
    }
}

}
