#pragma once

#include "../inc/linked_list.h"

#include <iostream>
#include <algorithm>

using namespace ns_LLIST;

/* #region Ctors  */
template <typename T>
LinkedList<T>::LinkedList() : count(0), head(new BaseNode<T>()), tail(new BaseNode<T>())
{
    head->next = tail;
    tail->prev = head;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) : LinkedList<T>()
{
    for (const auto &item : other)
        push_back(item);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList &&other)
{

    this->count = other.count;
    other.count = 0;
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(size_type _count, const T &value) : LinkedList<T>()
{
    for (size_type i = 0; i <= count; i++)
        push_back(value);
}

template <typename T>
LinkedList<T>::LinkedList(size_type _count) : LinkedList<T>()
{
    for (size_type i = 0; i <= _count; i++)
        push_back();
}

template <typename T>
template <typename InputIt>
LinkedList<T>::LinkedList(InputIt first, InputIt last) : LinkedList<T>()
{
    for (; first != last; ++first)
        push_back(*first);
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> init) : LinkedList<T>()
{
    for (const auto &item : init)
        push_back(item);
}
/* #endregion */

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
    delete (head);
    delete (tail);
}

/* #region Assigments  */
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    clear();

    for (const auto &item : other)
    {
        push_back(item);
    }
    return (*this);
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&other)
{
    if (&other == this)
        return (*this);

    if (count != 0)
        clear();

    this->count = other.count;
    other.count = 0;
    delete head;
    delete tail;
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    return *this;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(std::initializer_list<T> ilist)
{
    assign(ilist);
    return (*this);
}

template <typename T>
void LinkedList<T>::assign(size_type _count, const T &value)
{
    clear();
    count = _count;
    for (size_type i = 0; i < _count; i++)
        push_back(value);
}

template <typename T>
template <typename InputIt>
void LinkedList<T>::assign(InputIt first, InputIt last)
{
    clear();
    for (; first != last; ++first)
        push_back(*first);
}

template <typename T>
void LinkedList<T>::assign(std::initializer_list<T> ilist)
{
    clear();
    for (auto &item : ilist)
        push_back(std::move(item));
}
/* #endregion */

/* #region  push_back */
template <typename T>
void LinkedList<T>::push_back(const T &value)
{
    insert(cend(), value);
}

template <typename T>
void LinkedList<T>::push_back(T &&value)
{
    insert(cend(), std::move(value));
}

template <typename T>
void LinkedList<T>::push_back()
{
    insert(cend(), new T());
}
/* #endregion */

/* #region  push_front */

template <typename T>
void LinkedList<T>::push_front(const T &value)
{
    insert(cbegin(), value);
}

template <typename T>
void LinkedList<T>::push_front(T &&value)
{
    insert(cbegin(), std::move(value));
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
    if (pos._curr_ptr == cbegin()._curr_ptr->prev)
        throw std::runtime_error("Insert before the head");

    Node<T> *_node = new Node<T>(value);
    _node->prev = pos._curr_ptr->prev;
    _node->next = pos._curr_ptr;
    pos._curr_ptr->prev->next = _node;
    pos._curr_ptr->prev = _node;
    count++;
    return iterator(*(pos._curr_ptr));
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, T &&value)
{
    if (pos._curr_ptr == cbegin()._curr_ptr->prev)
        throw std::runtime_error("Insert past the tail");

    Node<T> *_node = new Node<T>(std::move(value));
    _node->prev = pos._curr_ptr->prev;
    _node->next = pos._curr_ptr;
    pos._curr_ptr->prev->next = _node;
    pos._curr_ptr->prev = _node;
    count++;
    return iterator(*(pos._curr_ptr));
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, size_type _count, const T &value)
{
    for (size_type i = 0; i < _count; i++)
    {
        insert(pos, value);
        --pos;
    }
    return iterator(*(pos._curr_ptr));
}

template <typename T>
template <typename InputIt>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, InputIt first, InputIt last)
{
    for (; first != last; --last)
    {
        insert(pos, *last);
        --pos;
    }
    return iterator(*(pos._curr_ptr));
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::insert(const_iterator pos, std::initializer_list<T> ilist)
{
    for (auto it = std::rbegin(ilist); it != std::rend(ilist); ++it)
    {
        insert(pos, std::move(*it));
        --pos;
    }
    return iterator(*(pos._curr_ptr));
}
/* #endregion */

/* #region  pop */
template <typename T>
void LinkedList<T>::pop_back()
{
    erase(--cend());
}

template <typename T>
void LinkedList<T>::pop_front()
{
    erase(cbegin());
}
/* #endregion */

/* #region  erase */
template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(const_iterator pos)
{
    if (count == 0)
        throw std::runtime_error("List is empty");
    auto result = pos;
    ++result;
    pos._curr_ptr->prev->next = pos._curr_ptr->next;
    pos._curr_ptr->next->prev = pos._curr_ptr->prev;
    delete (pos._curr_ptr);
    count--;
    return iterator(*(result._curr_ptr));
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(const_iterator first, const_iterator last)
{
    if (count == 0)
        throw std::runtime_error("List is empty");

    auto result = first;
    for (; first != last;)
    {
        ++result;
        first = const_iterator(*erase(first)._curr_ptr);
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
bool LinkedList<T>::operator==(const LinkedList<T> &l2)
{
    if (count != l2.count)
        return false;
    auto it1 = this->begin();
    auto it2 = l2.begin();
    for (; it1 != this->end(); ++it1, ++it2)
        if (*it1 != *it2)
            return false;
    return true;
}

template <typename T>
bool LinkedList<T>::operator!=(const LinkedList<T> &l2)
{
    return !(*this == l2);
}

template <typename T>
bool LinkedList<T>::empty() const noexcept
{
    return 0 == count;
}

template <typename T>
void LinkedList<T>::clear()
{
    if (count == 0)
        return;

    for (; count != 0;)
        pop_back();

    head->next = tail;
    tail->prev = head;
}

template <typename T>
void LinkedList<T>::print() const
{
    for (const auto &item : *this)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::reverse() noexcept
{
    if (count == 0 || count == 1)
        return;

    BaseNode<T> *t_tail = head;
    BaseNode<T> *current = head;
    BaseNode<T> *temp = nullptr;
    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    head = temp->prev;
    tail = t_tail;
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T> &other) noexcept
{
    std::swap(*this, other);
}

/* #region  sort */
template <typename T>
void LinkedList<T>::sort()
{
    sort(std::less_equal<T>{});
}

template <typename T>
template <typename Compare>
void LinkedList<T>::sort(Compare comp) // merge sort
{
    merge_sort(begin(), end(), comp);
}

template <typename T>
template <typename InputIt, typename Compare>
void LinkedList<T>::merge_sort(InputIt beg, InputIt end, Compare comp)
{
    size_type size = std::distance(beg, end);
    if (size <= 1)
        return;

    auto mid = std::next(beg, size / 2);
    merge_sort(beg, mid, comp);
    merge_sort(mid, end, comp);
    merge(beg, mid, end, comp);
}

template <typename T>
template <typename InputIt, typename Compare>
void LinkedList<T>::merge(InputIt beg, InputIt mid, InputIt end, Compare comp)
{
    std::vector<value_type> temp;
    temp.reserve(std::distance(beg, end));
    InputIt left = beg;
    InputIt right = mid;

    while (left != mid && right != end)
    {
        if (comp(*right, *left))
            temp.emplace_back(*right++);
        else
            temp.emplace_back(*left++);
    }
    temp.insert(temp.end(), left, mid);
    temp.insert(temp.end(), right, end);

    std::move(temp.begin(), temp.end(), beg);
}
/* #endregion */

/* #region  unique */
template <typename T>
typename LinkedList<T>::size_type LinkedList<T>::unique()
{
    return unique([](const auto &left, const auto &right)
                  { return left == right; });
}

template <typename T>
template <typename BinaryPredicate>
typename LinkedList<T>::size_type LinkedList<T>::unique(BinaryPredicate p)
{
    auto first = cbegin();
    if (first == cend())
        return count;

    auto second = ++cbegin();
    for (; second != cend();)
    {
        if (p(*first, *second))
        {
            erase(first);
            first = second;
            ++second;
        }
        else
        {
            ++first;
            ++second;
        }
    }
    return count;
}
/* #endregion */

/* #region  remove */
template <typename T>
typename LinkedList<T>::size_type LinkedList<T>::remove(const T &value)
{
    return remove_if([&value](auto &item)
                     { return item == value; });
}

template <typename T>
template <typename UnaryPredicate>
typename LinkedList<T>::size_type LinkedList<T>::remove_if(UnaryPredicate p)
{
    auto it = cbegin();
    size_type cnt = 0;
    for (; it != cend();)
    {
        if (p(*it))
        {
            it = const_iterator(*erase(it)._curr_ptr);
            ++cnt;
        }
        else
            ++it;
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
        for (size_type i = 0; i < count - _count; i++)
            pop_back();
    }
    else
    {
        for (size_type i = 0; i < _count - count; i++)
            push_back(value);
    }
}

template <typename T>
void LinkedList<T>::resize(size_type _count)
{
    if (_count <= count)
    {
        for (size_type i = 0; i < count - _count; i++)
            pop_back();
    }
    else
    {
        for (size_type i = 0; i < _count - count; i++)
            push_back();
    }
}
/* #endregion */