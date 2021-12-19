#include <iostream>
#include <filesystem>
#include <queue>
#include <cmath>
//#include <chrono>
#include <cstring>

#include "ThreadPool.h"

#define max(a, b) a > b ? a : b

namespace fs = std::filesystem;

struct [[maybe_unused]] HumanReadable {
    std::uintmax_t size{};
private: friend
    std::ostream& operator<<(std::ostream& os, HumanReadable hr) {
        int i{};
        double mantissa = hr.size;
        for (; mantissa >= 1024.; mantissa /= 1024., ++i) { }
        mantissa = std::ceil(mantissa * 10.) / 10.;
        os << mantissa << "BKMGTPE"[i];
        return i == 0 ? os : os << "B (" << hr.size << " B)";
    }
};

class Size {
private:
    std::string task;
    uint64_t size;
public:

    explicit Size(std::string task): task(std::move(task)), size(0) {}
    void inc(size_t s) { size += s;};
    ~Size () {
//        auto now = std::chrono::system_clock::now();
//        auto in_time_t = std::chrono::system_clock::to_time_t(now);

//        std::cout << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");

        std::cout << "> " << task << ": " <<  HumanReadable{size} << std::endl;
    }
};

void check_dir_threading(const std::string& start_dir, ThreadPool &pool, std::shared_ptr<Size> &size) {
    try {
        fs::directory_iterator begin(start_dir);
        fs::directory_iterator end;
        for (; begin != end; ++begin) {
            try {
                if (fs::is_directory(begin->path())) {
                    pool.push(check_dir_threading, begin->path(), std::ref(pool), size);
                } else if (!fs::is_symlink(begin->path())){
                    size->inc(fs::file_size(begin->path()));
                }
            } catch (fs::filesystem_error &e) {}
        }
    } catch(fs::filesystem_error &e) {}
}

void start_task(const std::string& name, const std::string& task, ThreadPool &pool) {
    pool.push(check_dir_threading, task, std::ref(pool), std::make_shared<Size>(name));
}

void run_test_tasks(ThreadPool &pool) {

    std::vector<std::string> v {
            "/Users/u53r/CLionProjects",
            "/Users/u53r/PycharmProjects",
            "/Users/u53r/miniforge3",
            "/Users/u53r/Projects",
            "/Users/u53r/",
            "/Users/u53r/Downloads",
            "/Users/u53r/Documents",
            "/Users/u53r/Applications",
            "/Users/u53r/Desktop",
    };

    for (auto& task: v) {
        start_task(task, task, pool);
    }
    for (auto& task: v) {
        start_task(task, task, pool);
    }
    for (auto& task: v) {
        start_task(task, task, pool);
    }
}

int main(int argc, char **argv) {

    int threads = 1;
    for (int i=0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    if ((argc == 3) && (!strcmp(argv[1], "-t") || !strcmp(argv[1], "--threads")))
        threads = max(std::stoi(argv[2]), 1);

    ThreadPool pool(threads);
    std::cout << "Using " << threads << " thread(s)!" << std::endl;
//    auto start = std::chrono::high_resolution_clock::now();
//
//    auto now = std::chrono::system_clock::now();
//    auto in_time_t = std::chrono::system_clock::to_time_t(now);

//    std::cout << "Start " << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << std::endl;
//    run_test_tasks(pool);

    std::string arg;
    while(true) {
        std::cin >> arg;
        if (arg == ":exit") {
            std::cout << "Awaiting incompleted tasks!" << std::endl;
            pool.close();
            break;
        }
        if (arg == ":cancel") {
            std::cout << "Cancelling incompleted tasks!" << std::endl;
            pool.clear();
        }
        else {
            std::cout << "Starting task " << arg << "!" << std::endl;
            start_task(arg, arg, pool);
        }
    }
}