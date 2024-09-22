#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

namespace robocode {

template<typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() = default;

    void enqueue(const T &value);
    T dequeue();
    bool empty() const;

private:
    std::queue<T> queue;
    mutable std::mutex mutex;
    std::condition_variable condition;
};

template<typename T>
void Queue<T>::enqueue(const T &value) {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(value);
    condition.notify_one();
}

template<typename T>
T Queue<T>::dequeue() {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [this]() {
        return !queue.empty();
    });
    const T value = queue.front();
    queue.pop();
    return value;
}

template<typename T>
bool Queue<T>::empty() const {
    std::lock_guard<std::mutex> lock(mutex);
    return queue.empty();
}

}
