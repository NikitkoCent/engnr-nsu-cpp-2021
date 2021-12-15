#include <iostream>
#include "dirwalker/SafeQueue.h"
#include "dirwalker/ThreadPool.h"

using namespace std;

int worker(string path){
    cout << "Test" << endl;
    return 1337;
}

int main() {
//    ThreadPool tp(4);
//
//    for (int i = 0; i < 100; ++i) {
//        tp.push<int(string)>(bind(worker, "test"))
//    }
//    Task<function<int()>> t1(move([] { return 1337; }));

//    auto t1 = [] { return 1337; };
//
//    auto a = 1;
//
//    Task<int> t2([&a] { return a; });
//
//    a=228;
//
//    cout << t2.run() << endl;
//    ThreadPool<int> tp(10);
//
//    for (int i = 0; i < 1313; ++i) {
//        tp.submit(move([i]{ return i; }));
//    }

    Task<int> t1(move([] { return 1337; }));


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
