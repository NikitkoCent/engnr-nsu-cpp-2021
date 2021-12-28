//
// Created by Mikhail Okan on 18.12.2021.
//

#include "SafeQueue.h"

bool SafeQueue::empty() {
    std::unique_lock<std::mutex> lock(sq_mutex);
    return sf_queue.empty();
}

void SafeQueue::push(std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(sq_mutex);
    sf_queue.push(task);
    cond.notify_one();
}

bool SafeQueue::pop(std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(sq_mutex);
    if (!stop_cmd) {
        while (sf_queue.empty() && !stop_cmd) {
            cond.wait(lock);
        }
        if (!sf_queue.empty()) {
            task = std::move(sf_queue.front());
            sf_queue.pop();
            return true;
        }
    }
    return false;
}

void SafeQueue::clear() {
    std::unique_lock<std::mutex> lock(sq_mutex);
    while (!sf_queue.empty()) {
        sf_queue.pop();
    }
}

void SafeQueue::close() {
    std::unique_lock<std::mutex> lock(sq_mutex);
    stop_cmd = true;
    cond.notify_all();
    clear();
}