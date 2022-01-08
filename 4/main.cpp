#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>

#include "dirwalker/SafeQueue.h"
#include "dirwalker/ThreadPool.h"

#ifdef USE_BOOST_FS
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::move;

unsigned long long worker(ThreadPool<unsigned long long> &tp, const string &file, std::atomic<bool> &cancel) {
    cout << "Starting worker for " << &tp << " " << file << endl;
    unsigned long long sz = 0;
    int cnt = 0;
    vector<std::future<unsigned long long>> futs;

    for (auto &p: fs::recursive_directory_iterator(file)) {
        if (is_regular_file(p) && !cancel) {
            auto task_fut = tp.submit(move([p] {
                auto sz = fs::file_size(p.path());
                return sz;
            }));
            futs.emplace_back(move(task_fut));
//            cout << "\rFiles: " << cnt <<"           ";
            cnt++;
        } else if (cancel) {
            cout << "Task" << file << " was canceled!" << endl;
            return 0;
        }
    }

    cout << endl << "Waiting for tasks to finish..." << endl;

    for (auto &fut : futs) {
        sz += fut.get();
    }

    cout << "Size of " << file << ": " << sz << endl;

    return sz;
}


int main(int argc, char **argv) {

    string cmd;
    std::atomic<bool> cancel = false;
    ThreadPool<unsigned long long> task_pool(4);
    ThreadPool<unsigned long long> subtask_pool;

    cout << &subtask_pool << endl;

    cout << "Wait till tasks done!" << endl;

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
            cancel = true;
            task_pool.cancel_all();
            subtask_pool.cancel_all();
            while (task_pool.active_count() > 0) std::this_thread::sleep_for(std::chrono::milliseconds(5));
            cancel = false;
        } else if (!cmd.empty()) {
            task_pool.submit(move([&subtask_pool, cmd, &cancel] { return worker(subtask_pool, cmd, cancel); }));
        } else {
            cout << "Cnt: " << task_pool.task_count() << " " << subtask_pool.task_count() << endl;
        }
    }

    cout << "Tasks done!" << endl;

    std::cout << std::endl;
    return 0;
}
