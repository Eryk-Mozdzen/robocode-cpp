#include <thread>
#include <chrono>

#include <robocode/Engine.h>

int main() {
	std::vector<robocode::RobotFactory> factories;
	factories.emplace_back("../../ExampleBot/build/ExampleBot.so");

	const robocode::Engine engine(factories);

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
