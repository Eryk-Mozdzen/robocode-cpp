#include "RobotFactory.h"
#include <iostream>
#include <dlfcn.h>

RobotFactory::RobotFactory(const std::string &path) {
    handle = dlopen(path.c_str(), RTLD_LAZY);

    if(!handle) {
        std::cerr << "Error loading the library: " << dlerror() << std::endl;
    }

    factory = (Factory)dlsym(handle, "create");

    if(!factory) {
        std::cerr << "Error finding the function: " << dlerror() << std::endl;
    }
}

RobotFactory::~RobotFactory() {
    if(handle) {
        dlclose(handle);
    }
}

std::unique_ptr<robocode::Robot> RobotFactory::create() const {
    if(factory) {
        return factory();
    }

    return nullptr;
}
