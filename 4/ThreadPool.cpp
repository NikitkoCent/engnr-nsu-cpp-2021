//
// Created by Mikhail Okan on 18.12.2021.
//

#include "ThreadPool.h"
void ThreadPool::thread_manager() {
    bool found_task;
    while (!stop_cmd) {
        std::function<void()> func;
        std::unique_lock<std::mutex> lock(tp_mutex);
        if (tp_queue.empty()) {
            tp_cond.wait(lock);
        }
        found_task = tp_queue.pop(func);
        lock.unlock();

        if (found_task)
            func();
    }
}

void ThreadPool::init() {
    stop_cmd = false;
    for (auto & tp_thread : tp_threads)
        tp_thread = std::thread(&ThreadPool::thread_manager, this);
}

void ThreadPool::join() {
    tp_cond.notify_all();
    for (auto & thread : tp_threads)
        thread.join();
}

void ThreadPool::close() {
    stop_cmd = true;
    join();
}

void ThreadPool::clear() {
    close();
    tp_queue.clear();
    init();
}