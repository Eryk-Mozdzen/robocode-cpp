#include <iostream>
#include <dlfcn.h>

#include <robocode/RobotFactory.h>

namespace robocode {

RobotFactory::RobotFactory(const std::string &path) : handle{nullptr}, factory{nullptr} {
    handle = dlopen(path.c_str(), RTLD_LAZY);

    if(!handle) {
        std::cerr << "Error loading the library: " << dlerror() << std::endl;
    }

    factory = reinterpret_cast<Factory>(dlsym(handle, "create"));

    const char *error = dlerror();
    if(error) {
        std::cerr << "Error finding the function: " << error << std::endl;
        dlclose(handle);
        handle = nullptr;
        factory = nullptr;
    }
}

RobotFactory::RobotFactory(RobotFactory &&other) : handle{other.handle}, factory{other.factory} {
    other.handle = nullptr;
    other.factory = nullptr;
}

RobotFactory::~RobotFactory() {
    if(handle) {
        dlclose(handle);
    }
}

RobotFactory & RobotFactory::operator=(RobotFactory &&other) {
    if(this!=&other) {
        if(handle) {
            dlclose(handle);
        }

        handle = other.handle;
        factory = other.factory;
        other.handle = nullptr;
        other.factory = nullptr;
    }

    return *this;
}

std::unique_ptr<robocode::Robot> RobotFactory::create() const {
    if(factory) {
        return factory();
    }

    return nullptr;
}

}
