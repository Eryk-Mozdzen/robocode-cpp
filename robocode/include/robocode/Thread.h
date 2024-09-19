#pragma once

#include <atomic>
#include <thread>

namespace robocode {

template<class T>
class Thread {
    T *object;
    void (T::*method)();

    std::atomic<bool> running;
    std::thread thread;

    void run();

public:
    Thread(T *object, void (T::*method)());
    ~Thread();

    void start();
    void stop();
};


template<class T>
Thread<T>::Thread(T *object, void (T::*method)()) : object{object}, method{method} {

}

template<class T>
Thread<T>::~Thread() {
    running = false;
    if(thread.joinable()) {
        thread.join();
    }
}

template<class T>
void Thread<T>::start() {
    running = true;
    thread = std::thread(&Thread<T>::run, this);
}

template<class T>
void Thread<T>::stop() {
    running = false;
    if(thread.joinable()) {
        thread.join();
    }
}

template<class T>
void Thread<T>::run() {
    while(running) {
        (object->*method)();
    }
}

}
