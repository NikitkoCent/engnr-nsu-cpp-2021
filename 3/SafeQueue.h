//
// Created by Mikhail Okan on 18.12.2021.
//

#ifndef THREADS_SAFEQUEUE_H
#define THREADS_SAFEQUEUE_H

#include <mutex>
#include <queue>
#include <iostream>

class SafeQueue {
private:
    std::queue<std::function<void()>> sf_queue;
    std::mutex sq_mutex;
public:
    SafeQueue() = default;
    ~SafeQueue() = default;

    size_t size();

    bool empty();

    void push(std::function<void()>& task);

    bool pop(std::function<void()>& task);

    void clear();
};


#endif //THREADS_SAFEQUEUE_H
