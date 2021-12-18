#include <iostream>
#include <string>

#include "dirwalker/SafeQueue.h"
#include "dirwalker/ThreadPool.h"

#ifdef _WIN32
#include <Windows.h>
#else

#include <unistd.h>

#endif

#include <iostream>
#include <cstdlib>

using namespace std;

#ifdef USE_BOOST_FS
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

unsigned long long worker(ThreadPool<int> &tp, const string &file) {
    cout << "Starting worker for " << &tp << " " << file << endl;
    unsigned long long sz = 0;
    vector<std::future<int>> futs;

    for (auto &p: fs::recursive_directory_iterator(file)) {
        if (is_regular_file(p)) {
//            cout << "File: " << p.path() << endl;
            auto task_fut = tp.submit(move([p] {
                auto sz = fs::file_size(p.path());
//                cout << "size of " << p.path() << " is " << sz << endl;
                return sz;
            }));
            futs.emplace_back(move(task_fut));
        }
    }
    cout << "Waiting for tasks to finish..." << endl;

    for (auto &fut : futs) {
        sz += fut.get();
    }

    cout << "Size of " << file << ": " << sz << endl;

    return sz;
}


int main() {
    string cmd;
    ThreadPool<unsigned long long> task_pool(1);
    ThreadPool<int> subtask_pool;

    cout << &subtask_pool << endl;

//    auto future = tp.submit([]{ return 228;});

//    cout << future.get() << endl;

//    int cnt = 10;
//
//    vector<std::__1::future<int>> futs(cnt);
//
//    for (int i = 0; i < cnt; ++i) {
////        cout << "Submit " << i << endl;
//        futs[i] = tp.submit(move([i]{ std::this_thread::sleep_for(std::chrono::seconds(5)); return i; }));
//    }
    cout << "Wait till tasks done!" << endl;

//    for (auto &fut : futs) {
//        cout << fut.get() << endl;
//    }

    while (true) {
        cout << "> ";
        getline(cin, cmd);
        if (cmd == ":exit" || cmd == ":q" || cmd == ":c") {
            cout << "Stopping threads!" << endl;
            task_pool.join();
            subtask_pool.join();
            break;
        } else if (cmd == ":cancel") {
            cout << "Canceling tasks!" << endl;
            task_pool.cancel_all();
            subtask_pool.cancel_all();
        } else if (!cmd.empty()) {
            task_pool.submit(move([&subtask_pool, cmd] { return worker(subtask_pool, cmd); }));
        } else {
            cout << "Cnt: " << task_pool.task_count() << " " << subtask_pool.task_count() << endl;
        }
    }

    cout << "Tasks done!" << endl;

//    for (auto &fut : futs) {
//        cout << fut.get() << " ";
//    }


//    Task<int> t1([a=228]{ return a; });

//    SafeQueue<int> a;
//    int b = 2;
//    a.push(b);

    std::cout << std::endl;
    return 0;
}
