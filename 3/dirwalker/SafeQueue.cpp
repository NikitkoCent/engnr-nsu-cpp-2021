//
// Created by gav on 10/12/2021.
//

#include "SafeQueue.h"
#include <iostream>

/**
 * Pushes element to the end of queue
 * @tparam T class
 * @param elem element
 */
template<typename T>
void SafeQueue<T>::push(T &elem) {
    std::lock_guard<std::mutex> lock(m);
    q.push(elem);
    this->length++;
}

/**
 * Returns first element of the queue. Waits for mutex.
 * @tparam T
 * @return first element of the queue
 */
template<typename T>
T SafeQueue<T>::next() {
    T elem = nullptr;
    m.lock();
    if (!q.empty()) {
        elem = q.front();
        q.pop();
        this->length--;
    }
    m.unlock();
    return elem;
}

template<typename T>
bool SafeQueue<T>::is_empty() {
    bool empty = true;
    empty = this->q.empty();
    return empty;
}

template<typename T>
int SafeQueue<T>::get_length() {
    return this->q.size();
}
