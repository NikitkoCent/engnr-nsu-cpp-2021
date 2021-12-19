//
// Created by Mikhail Okan on 18.12.2021.
//

#include "SafeQueue.h"

size_t SafeQueue::size() {
    std::unique_lock<std::mutex> lock(sq_mutex);
    return sf_queue.size();
}

bool SafeQueue::empty() {
    std::unique_lock<std::mutex> lock(sq_mutex);
    return sf_queue.empty();
}

void SafeQueue::push(std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(sq_mutex);
    sf_queue.push(task);
}

bool SafeQueue::pop(std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(sq_mutex);
    if (!sf_queue.empty())  {
        task = std::move(sf_queue.front());
        sf_queue.pop();
        return true;
    }
    return false;
}

void SafeQueue::clear() {
    std::unique_lock<std::mutex> lock(sq_mutex);
    while (!sf_queue.empty()) {
        sf_queue.pop();
    }
}