//
// Created by gav on 10/12/2021.
//

#ifndef INC_3_THREADPOOL_H
#define INC_3_THREADPOOL_H


#include "SafeQueue.h"
#include <thread>
#include <vector>
#include <future>

class ThreadPool {
    // Task function
    using task_type = std::function<void()>;

public:
    explicit ThreadPool(std::size_t thread_count = std::thread::hardware_concurrency()) {
        for (std::size_t i{0}; i < thread_count; ++i) {
            m_workers.emplace_back(std::bind(&ThreadPool::thread_loop, this));
        }
    }

    ~ThreadPool() {
        if (m_workers.size() > 0) {
            join();
        }
    }

    template<typename functype>
    auto push(std::function<functype> &fn) {
        auto task{std::make_shared<std::packaged_task<functype>>(fn)};

        auto future{task->get_future()};
        std::unique_lock<std::mutex> lock{m_mutex};

        m_tasks.emplace([task]() {
            (*task)();
        });

        lock.unlock();
        m_notifier.notify_one();
        return future;
    }

    void clear() {
        std::unique_lock<std::mutex> lock{m_mutex};

        while (!m_tasks.empty()) {
            m_tasks.pop();
        }
    }

    void join() {
        m_stop = true;
        m_notifier.notify_all();

        for (auto &thread : m_workers) {
            if (thread.joinable()) {
                thread.join();
            }
        }

        m_workers.clear();
    }

    std::size_t thread_count() const {
        return m_workers.size();
    }

    std::size_t active_count() const {
        return m_active;
    }

private:
    void thread_loop() {
        while (true) {
            // Wait for a new task
            auto task{next_task()};

            if (task) {
                ++m_active;
                task();
                --m_active;
            } else if (m_stop) {
                // No more task + stop required
                break;
            }
        }
    }

    task_type next_task() {
        std::unique_lock<std::mutex> lock{m_mutex};

        m_notifier.wait(lock, [this]() {
            return !m_tasks.empty() || m_stop;
        });

        if (m_tasks.empty()) {
            return {};
        }

        auto task{m_tasks.front()};
        m_tasks.pop();
        return task;
    }

    std::atomic<bool> m_stop{false};
    std::atomic<std::size_t> m_active{0};

    std::condition_variable m_notifier;
    std::mutex m_mutex;

    std::vector<std::thread> m_workers;
    std::queue<task_type> m_tasks;
};


#endif //INC_3_THREADPOOL_H
