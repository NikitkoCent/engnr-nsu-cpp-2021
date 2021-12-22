//
// Created by Mikhail Okan on 18.12.2021.
//

#ifndef THREADS_SAFEQUEUE_H
#define THREADS_SAFEQUEUE_H

#include <mutex>
#include <queue>
#include <functional>

class SafeQueue {
private:
    std::queue<std::function<void()>> sf_queue;
    std::mutex sq_mutex;
    std::condition_variable cond;
    std::mutex wait_mutex;
    bool stop_cmd;
public:
    SafeQueue(): stop_cmd(false) {}
    ~SafeQueue() = default;

    bool empty();

    void push(std::function<void()>& task);

    bool pop(std::function<void()>& task);

    void clear();

    void close();
};


#endif //THREADS_SAFEQUEUE_H
