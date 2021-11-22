#pragma once

#include "../inc/linked_list.h"

#include <iostream>
#include <algorithm>

using namespace ns_LLIST;

/* #region Assigments  */
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    clear();

    for (auto item : other)
    {
        push_back(*item);
    }
    return (*this);
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&other)
{
    if (other == this)
        return (*this);

    clear();

    head = other.head;
    tail = other.tail;
    count = other.count;
    other.head = nullptr;
    other.tail = nullptr;
    return (*this);
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(std::initializer_list<T> ilist)
{
    clear();

    for (auto item : ilist)
        push_back(std::move(item));

    return (*this);
}

template <typename T>
void LinkedList<T>::assign(size_type _count, const T &value)
{
    clear();
    count = _count;
    for (int i = 0; i < _count; i++)
        push_back(value);
}

template <typename T>
template <typename InputIt>
void LinkedList<T>::assign(InputIt first, InputIt last)
{
    clear();
    for (; first != last; first++)
        push_back(*first);
}

template <typename T>
void LinkedList<T>::assign(std::initializer_list<T> ilist)
{
    clear();
    for (auto item : ilist)
        push_back(item);
}
/* #endregion */

/* #region  push_back */
template <typename T>
void LinkedList<T>::push_back(const T &value)
{
    Node<T> *item = new Node<T>(value);
    item->prev = tail->prev;
    item->next = tail;
    tail->prev->next = item;
    tail->prev = item;
    count++;
}

template <typename T>
void LinkedList<T>::push_back(T &&value)
{
    Node<T> *item = new Node<T>(std::move(value));
    item->prev = tail->prev;
    item->next = tail;
    tail->prev->next = item;
    tail->prev = item;
    count++;
}

template <typename T>
void LinkedList<T>::push_back()
{
    Node<T> *item = new Node<T>();
    item->prev = tail->prev;
    item->next = tail;
    tail->prev->next = item;
    tail->prev = item;
    count++;
}
/* #endregion */

/* #region  push_front */

template <typename T>
void LinkedList<T>::push_front(const T &value)
{
    Node<T> *item = new Node<T>(value);
    item->next = head->next;
    item->prev = head;
    head->next->prev = item;
    head->next = item;
    count++;
}

template <typename T>
void LinkedList<T>::push_front(T &&value)
{
    Node<T> *item = new Node<T>(std::move(value));
    item->next = head->next;
    item->prev = head;
    head->next->prev = item;
    head->next = item;
    count++;
}

template <typename T>
void LinkedList<T>::push_front()
{
    Node<T> *item = new Node<T>();
    item->next = head->next;
    item->prev = head;
    head->next->prev = item;
    head->next = item;
    count++;
}
/* #endregion */

/* #region insert  */
template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, const T &value)
{
    if (pos == cend()) throw std::runtime_error("Insert past the tail");

    Node<T> *_node = new Node<T>(value);
    _node->next = pos._curr_ptr->next;
    _node->prev = pos._curr_ptr;
    pos._curr_ptr->next->prev = _node;
    pos._curr_ptr->next = _node;
    count++;
    return iterator(*(pos._curr_ptr));
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, T &&value)
{
    if (pos == cend()) throw std::runtime_error("Insert past the tail");

    Node<T> *_node = new Node<T>(std::move(value));
    _node->next = pos._curr_ptr->next;
    _node->prev = pos._curr_ptr;
    pos._curr_ptr->next->prev = _node;
    pos._curr_ptr->next = _node;
    count++;
    return iterator(*(pos._curr_ptr));
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, size_type _count, const T &value)
{
    for (int i = 0; i < _count; i++)
    {
        insert(pos, value);
        pos++;
    }
    return pos;
}

template <typename T>
template <typename InputIt>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, InputIt first, InputIt last)
{
    for (; first != last; ++first)
    {
        insert(pos, *first);
        pos++;
    }
    return pos;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, std::initializer_list<T> ilist)
{
    for (auto item : ilist)
    {
        insert(pos, item);
        pos++;
    }
    return pos;
}
/* #endregion */

/* #region  pop */
template <typename T>
void LinkedList<T>::pop_back()
{
    if (count == 0)
        throw std::runtime_error("List is empty");
    tail->prev = tail->prev->prev;
    delete (tail->prev->next);
    count--;
    tail->prev->next = tail;
}

template <typename T>
void LinkedList<T>::pop_front()
{
    if (count == 0)
        throw std::runtime_error("List is empty");
    head->next = head->next->next;
    delete (head->next->prev);
    count--;
    head->next->prev = head;
}
/* #endregion */

/* #region  erase */
template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(const_iterator pos)
{
    auto result = pos;
    result++;
    pos._curr_ptr->prev->next = pos._curr_ptr->next;
    pos._curr_ptr->next->prev = pos._curr_ptr->prev;
    delete (pos._curr_ptr);
    count--;
    return iterator(*(result._curr_ptr));
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(const_iterator first, const_iterator last)
{
    auto result = first;
    for (; first != last;)
    {
        result++;
        first._curr_ptr->prev->next = first._curr_ptr->next;
        first._curr_ptr->next->prev = first._curr_ptr->prev;
        delete (first._curr_ptr);
        first._curr_ptr = result._curr_ptr;
        count--;
    }
    return iterator(*(result._curr_ptr));
}
/* #endregion */

template <typename T>
typename LinkedList<T>::size_type LinkedList<T>::size() const noexcept
{
    return count;
}

template <typename T>
bool LinkedList<T>::empty() const
{
    return 0 == count;
}

template <typename T>
void LinkedList<T>::clear() noexcept
{
    for (; count != 0;)
        pop_back();

    head->next = tail;
    tail->prev = head;
}

template <typename T>
void LinkedList<T>::print() const noexcept
{
    for (auto item : *this)
    {
        std::cout << item << std::endl;
    }
}

template <typename T>
void LinkedList<T>::reverse() noexcept
{
    LinkedList<T>* temp = new LinkedList<T>;
    for (auto i : *this)
        temp->push_front(std::move(i));

    this->clear();

    for (auto i : *temp)
        this->push_back(std::move(i));
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& other) noexcept
{
    LinkedList<T> temp = std::move(this);
    this = std::move(other);
    other = std::move(temp);
}

/* #region  sort */
template <typename T>
void LinkedList<T>::sort()
{
    std::sort(begin(), end());
}

template <typename T>
template <typename Compare>
void LinkedList<T>::sort(Compare comp)
{
    std::sort(begin(), end(), comp);
}
/* #endregion */

/* #region  unique */
template <typename T>
typename LinkedList<T>::size_type LinkedList<T>::unique()
{
    auto first = cbegin();
    if (first == cend())
        return count;

    auto second = ++cbegin();
    for (; second != cend();)
    {
        if (*first == *second)
        {
            erase(first);
            first = second++;
        }
        else
        {
            first++;
            second++;
        }
    }
    return count;
}

template <typename T>
template <typename BinaryPredicate>
typename LinkedList<T>::size_type LinkedList<T>::unique(BinaryPredicate p)
{
    auto first = cbegin();
    if (first == end())
        return count;

    auto second = ++begin();
    for (; second != cend();)
    {
        if (p(*first, *second))
        {
            erase(first);
            first = second++;
        }
        else
        {
            first++;
            second++;
        }
    }
    return count;
}
/* #endregion */

/* #region  remove */
template <typename T>
typename LinkedList<T>::size_type LinkedList<T>::remove(const T &value)
{
    auto it = cbegin();
    size_type cnt = 0;
    for (; it != cend();)
    {
        auto temp = it;
        temp++;
        if (*it == value)
        {
            erase(it);
            cnt++;
        }
        it = temp;
    }
    return cnt;
}

template <typename T>
template <typename UnaryPredicate>
typename LinkedList<T>::size_type LinkedList<T>::remove_if(UnaryPredicate p)
{
    auto it = cbegin();
    size_type cnt = 0;
    for (; it != cend(); it++)
    {
        auto temp = it;
        temp++;
        if (p(*it))
        {
            it = erase(it);
            cnt++;
            
        }
        it = temp;
    }
    return cnt;
}
/* #endregion */

/* #region  resize */
template <typename T>
void LinkedList<T>::resize(size_type _count, const value_type &value)
{
    if (_count <= count)
    {
        for (int i = 0; i < count - _count; i++)
            pop_back();
    }
    else
    {
        for (int i = 0; i < _count - count; i++)
            push_back(value);
    }
}

template <typename T>
void LinkedList<T>::resize(size_type _count)
{
    if (_count <= count)
    {
        for (int i = 0; i < count - _count; i++)
            pop_back();
    }
    else
    {
        for (int i = 0; i < _count - count; i++)
            push_back();
    }
}
/* #endregion */