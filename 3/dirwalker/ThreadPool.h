////
//// Created by gav on 10/12/2021.
////
//
#ifndef INC_3_THREADPOOL_H
#define INC_3_THREADPOOL_H
//
//
#include "SafeQueue.h"
#include <thread>
#include <vector>
#include <future>
#include <iostream>

//template<typename TaskT>
//class Task {
//    std::function<TaskT> task;
//
//public:
//    explicit Task(std::function<TaskT> &t){
//        task = t;
//    }
//
//    TaskT run() {
//        return TaskT.call();
//    }
//};

template<typename TaskT>
class Task {
    std::function<TaskT()> task;
    SafeQueue< std::function<TaskT()> > tasks;

public:
    explicit Task(std::function<TaskT()> &&t);
    TaskT run();
};

template<typename T>
Task<T>::Task(std::function<T()> &&t) {
    task = t;
    tasks.push(t);
    std::cout << "Tasks: " << &tasks << std::endl;
}

template<typename T>
T Task<T>::run() {
    tasks.next();
    return task();
}


//template<typename TaskT>
//class ThreadPool {
//    // Task function
//
//    std::atomic<bool> m_stop{false};
//    std::atomic<std::size_t> m_active{0};
//
//    std::condition_variable m_notifier;
//    std::mutex m_mutex;
//
//    std::vector<std::thread> m_workers;
//
//    SafeQueue< std::unique_ptr<Task<TaskT>> > tasks;
//
//public:
//    explicit ThreadPool(std::size_t thread_count = std::thread::hardware_concurrency()) {
////        tasks = new SafeQueue<Task<TaskT>>();
//
//        for (std::size_t i{0}; i < thread_count; ++i) {
//            m_workers.emplace_back(std::bind(&ThreadPool::thread_loop, this));
//        }
//    }
//
//    ~ThreadPool() {
//        if (m_workers.size() > 0) {
//            join();
//        }
//    }
//
//    auto submit(std::function<TaskT()> &&f) {
//        Task<TaskT> t( move(f) );
//
////        std::packaged_task<Task<TaskT>> task( std::move(t) );
////        auto future = task.get_future();
////        tasks.push(task);
////        m_notifier.notify_one();
////        return future;
//        return 0;
//    }
//
////    void clear() {
////        std::unique_lock<std::mutex> lock{m_mutex};
////
////        while (!m_tasks.empty()) {
////            m_tasks.pop();
////        }
////    }
//
//    void join() {
//        m_stop = true;
//        m_notifier.notify_all();
//
//        for (auto &thread : m_workers) {
//            if (thread.joinable()) {
//                thread.join();
//            }
//        }
//
//        m_workers.clear();
//    }
//
////    std::size_t thread_count() const {
////        return m_workers.size();
////    }
////
////    std::size_t active_count() const {
////        return m_active;
////    }
//
//private:
//    void thread_loop() {
//        while (true) {
//            if (m_stop) {
//                // No more task + stop required
//                break;
//            }
//
//            // Wait for a new task
//            auto task = next_task();
//
//            ++m_active;
//            task->run();
//            --m_active;
//        }
//    }
//
//    auto next_task() {
//        std::unique_lock<std::mutex> lock{m_mutex};
//
//        m_notifier.wait(lock, [this]() {
//            return !tasks.is_empty() || m_stop;
//        });
//
//        return tasks.next();
//    }
//
//
//};


#endif //INC_3_THREADPOOL_H
