//
// Created by gav on 10/12/2021.
//

#ifndef INC_3_SAFEQUEUE_H
#define INC_3_SAFEQUEUE_H

#include <mutex>
#include <queue>

template<typename T>
class SafeQueue {
    std::queue<T> q;
    std::mutex m;
    int length = 0;

public:
    void push(T &elem);
    T next();
    bool is_empty();
    int get_length();
};

#endif //INC_3_SAFEQUEUE_H
