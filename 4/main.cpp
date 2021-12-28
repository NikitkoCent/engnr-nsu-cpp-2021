#include <iostream>
#include <filesystem>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include "ThreadPool.h"
#include <atomic>

namespace fs = std::filesystem;


class Size {
private:
    fs::path task;
    std::atomic<uintmax_t> size;
public:
    explicit Size(std::string task): task(std::move(task)), size(0) {}
    void inc(uintmax_t s) { size += s; };
    ~Size () {
        std::cout << "> " << task << ": " <<  size << std::endl;
    }
};


void check_dir_threading(const std::string& start_dir, ThreadPool &pool, std::shared_ptr<Size> &size) {
    try {
        fs::directory_iterator begin(start_dir);
        fs::directory_iterator end;
        for (; begin != end; ++begin) {
            try {
                if (fs::is_directory(begin->path()) && !fs::is_symlink(begin->path())) {
                    pool.push(check_dir_threading, begin->path().string(), std::ref(pool), size);
                } else if (!fs::is_symlink(begin->path())){
                    size->inc(fs::file_size(begin->path()));
                }
            } catch (fs::filesystem_error &) {}
        }
    } catch(fs::filesystem_error &) {}
}


void start_task(const std::string& task, ThreadPool &pool) {
    pool.push(check_dir_threading, task, std::ref(pool), std::make_shared<Size>(task));
}


int main(int argc, char **argv) {
    int threads = 1;
    if ((argc == 3) && (!strcmp(argv[1], "-t") || !strcmp(argv[1], "--threads")))
        threads = std::max(std::stoi(argv[2]), 1);

//    /Users/u53r
//    /Users/u53r/Downloads
//    /Users/u53r/Projects
//    /Users/u53r/CLionProjects
//    /Users/u53r/PyCharmProjects
//    /Users/u53r/Documents
//    /Users/u53r/miniforge3
//    /Users/u53r/Projects/economy
//    /Users/u53r/Projects/huawei-geo-app
//    /Users/u53r/Projects/recommendations
//    /Users/u53r/Projects/discovery-proxy
//    /Users/u53r/Projects/Misc
//    /Users/u53r/Projects/ML
//    /Users/u53r/Projects/Disco
//    /Users/u53r/Projects/discovery-rpc
//    /Users/u53r/miniforge3/lib
//    /Users/u53r/miniforge3/bin
//    /Users/u53r/miniforge3/conda-meta
//    /Users/u53r/miniforge3/etc
//    /Users/u53r/miniforge3/include


    ThreadPool pool(threads);
    std::cout << "Using " << threads << " thread(s)!" << std::endl;

    std::string arg;
    while(true) {
        std::cin >> arg;
        if (arg == ":exit") {
            std::cout << "Awaiting incompleted tasks!" << std::endl;
            break;
        }
        if (arg == ":cancel") {
            std::cout << "Cancelling incompleted tasks!" << std::endl;
            pool.clear();
        }
        else {
            std::cout << "Starting task " << arg << "!" << std::endl;
            start_task(arg, pool);
        }
    }
    while (!pool.empty()) {}
    pool.close();
    return 0;
}