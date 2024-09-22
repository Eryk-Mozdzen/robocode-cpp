#include <vector>
#include <memory>
#include <utility>
#include <thread>
#include <chrono>
#include <cmath>

#include <robocode/Engine.h>
#include <robocode/Robot.h>
#include <robocode/RobotFactory.h>

namespace robocode {

Engine::Engine(const std::vector<RobotFactory> &factories) : thread{this, &Engine::loop} {
    for(const RobotFactory &factory : factories) {
        robots.push_back(factory.create());
    }

    for(const auto &robot : robots) {
        robot->thread.start();
    }

    thread.start();
}

Engine::~Engine() {
    thread.stop();

    for(const auto &robot : robots) {
        robot->thread.stop();
    }
}

void Engine::loop() {
    for(const auto &robot : robots) {
        while(!robot->queue.empty()) {
            const Robot::Command command = robot->queue.dequeue();

            switch(command.id) {
                case Robot::CommandId::FIRE: {
                    /*if(command.args.size()==1) {
                        const double strength = command.args[0];
                    }*/
                } break;
                case Robot::CommandId::VELOCITY: {
                    if(command.args.size()==2) {
                        const double left = command.args[0];
                        const double right = command.args[1];

                        constexpr double L = 1;

                        const double v = (right + left)/2;
                        const double w = (right - left)/L;

                        robot->velocity.x = v*std::cos(robot->orientation);
                        robot->velocity.y = v*std::sin(robot->orientation);
                        robot->angularVelocity = w;
                    }
                } break;
            }
        }

        constexpr double dt = 0.01;

        robot->position +=robot->velocity*dt;
        robot->orientation +=robot->angularVelocity*dt;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

}
