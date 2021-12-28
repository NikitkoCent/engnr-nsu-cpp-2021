//
// Created by Mikhail Okan on 18.12.2021.
//

#ifndef THREADS_THREADPOOL_H
#define THREADS_THREADPOOL_H

#include <future>
#include <memory>
#include <thread>
#include <functional>
#include <utility>
#include <vector>

#include "SafeQueue.h"

class ThreadPool {
private:
    void thread_manager();

    std::atomic<bool> stop_cmd{};
    SafeQueue tp_queue;
    std::vector<std::thread> tp_threads;
    std::mutex tp_mutex;

public:
    explicit ThreadPool(const int n_threads): tp_threads(std::vector<std::thread>(n_threads)) {init();}
    ~ThreadPool() = default;

    void init();

    void join();

    void close();

    void clear();

    bool empty();

    template<typename F, typename...A>
    auto push(F&& f, A&&... args) {
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...)) ()>>(std::bind(std::forward<F>(f), std::forward<A>(args)...));
        std::function<void()> wrapped = [task_ptr](){(*task_ptr)();};
        tp_queue.push(wrapped);
        return task_ptr->get_future();
    }
};


#endif //THREADS_THREADPOOL_H
