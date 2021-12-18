//
// Created by gav on 10/12/2021.
//

#ifndef INC_3_SAFEQUEUE_H
#define INC_3_SAFEQUEUE_H

#include <mutex>
#include <queue>

class QueueEmptyException : public std::runtime_error {
public:
    explicit QueueEmptyException() : std::runtime_error("Queue is empty!") {}
};

template<typename T>
class SafeQueue {
    std::queue<T> q;
    std::mutex m;
    int length = 0;

public:
    void push(T &elem);
    T next();
    bool empty();
    int get_length();
};

/**
 * Pushes element to the end of queue
 * @tparam T class
 * @param elem element
 */
template<typename T>
void SafeQueue<T>::push(T &elem) {
    std::lock_guard<std::mutex> lock(m);
    q.push(move(elem));
    this->length++;
}

/**
 * Returns first element of the queue. Waits for mutex.
 * @tparam T
 * @return first element of the queue
 */
template<typename T>
T SafeQueue<T>::next() {
//    T elem;
    if (q.empty()) {
        throw QueueEmptyException();
    }
    m.lock();
    auto elem = move(q.front());
    q.pop();
    this->length--;
    m.unlock();
    return elem;
}

template<typename T>
bool SafeQueue<T>::empty() {
    bool empty = true;
    empty = this->q.empty();
    return empty;
}

template<typename T>
int SafeQueue<T>::get_length() {
    return this->q.size();
}

#endif //INC_3_SAFEQUEUE_H