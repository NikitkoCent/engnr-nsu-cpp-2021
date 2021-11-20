#pragma once

#include <cstdint>
#include <stdexcept>
#include <initializer_list>

#include "node.h"
#include "iterators.h"

namespace ns_LLIST
{
    template <class T>
    class LinkedList
    {
    public:
        using value_type = T;
        using size_type = std::int16_t;
        using difference_type = std::ptrdiff_t;
        using reference = BaseNode<T> &;
        using const_reference = const BaseNode<T> &;
        using pointer = BaseNode<T> *;
        using const_pointer = const BaseNode<T> *;

        using iterator = Iterator<T, false>;
        using const_iterator = ConstIterator<T, false>;
        using reverse_iterator = Iterator<T, true>;
        using const_reverse_iterator = ConstIterator<T, true>;

    private:
        std::int16_t count;
        BaseNode<T> *head;
        BaseNode<T> *tail;

    public:
        LinkedList() : head(new BaseNode<T>()), tail(new BaseNode<T>()), count(0)
        {
            head->next = tail;
            tail->prev = head;
        }

        LinkedList(const LinkedList &other) : LinkedList<T>()
        {
            for (auto item : other)
                push_front(item);
        };

        LinkedList(LinkedList &&other)
        {
            if (other == this)
                return;

            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }

        LinkedList(size_type _count, const T &value) : LinkedList<T>()
        {
            for (int i = 0; i <= count; i++)
                push_back(value);
        }

        explicit LinkedList(size_type _count) : LinkedList<T>()
        {
            for (int i = 0; i <= _count; i++)
                push_back();
        }

        template <typename InputIt>
        LinkedList(InputIt first, InputIt last) : LinkedList<T>()
        {
            for (; first != last; first++)
                push_back(*first);
        }

        LinkedList(std::initializer_list<T> init) : LinkedList<T>()
        {
            for (auto item : init)
                push_front(item);
        }
        ~LinkedList() { clear(); }

    public:
        LinkedList &operator=(const LinkedList &other);
        LinkedList &operator=(LinkedList &&other);
        LinkedList &operator=(std::initializer_list<T> ilist);

        void assign(size_type _count, const T &value);
        template <typename InputIt>
        void assign(InputIt first, InputIt last);
        void assign(std::initializer_list<T> ilist);

    public:
        reference front() { return *(head); }

        const_reference front() const { return *(head); }

        reference back() { return *(tail); }

        const_reference back() const { return *(tail); }

    public:
        iterator begin() noexcept { return iterator(*(front().next)); }

        const_iterator begin() const noexcept { return const_iterator(*(front().next)); }

        const_iterator cbegin() const noexcept { return const_iterator(*(front().next)); }

        iterator end() noexcept { return iterator(back()); }

        const_iterator end() const noexcept { return const_iterator(back()); }

        const_iterator cend() const noexcept { return const_iterator(back()); }

    public:
        reverse_iterator rbegin() noexcept { return reverse_iterator(back().prev); }

        const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(back().prev); }

        const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(back().prev); }

        reverse_iterator rend() noexcept { return reverse_iterator(front()); }

        const_reverse_iterator rend() const noexcept { return const_reverse_iterator(front()); }

        const_reverse_iterator crend() const noexcept { return const_reverse_iterator(front()); }

    public:
        size_type size() const noexcept;
        [[nodiscard]] bool empty() const;

    public:
        iterator insert(const_iterator pos, const T &value);
        iterator insert(const_iterator pos, T &&value);
        iterator insert(const_iterator pos, size_type _count, const T &value);

        template <typename InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last);
        iterator insert(const_iterator pos, std::initializer_list<T> ilist);

        void push_front(const T &value);
        void push_front(T &&value);
        void push_front();

        void push_back(const T &value);
        void push_back(T &&value);
        void push_back();

    public:
        iterator erase(const_iterator pos);
        iterator erase(const_iterator first, const_iterator last);

        void pop_back();
        void pop_front();

    public:
        void sort();
        template <typename Compare>
        void sort(Compare comp);

        size_type unique();
        template <typename BinaryPredicate>
        size_type unique(BinaryPredicate p);

        void reverse() noexcept;

        size_type remove(const T &value);
        template <typename UnaryPredicate>
        size_type remove_if(UnaryPredicate p);

    public:
        void print() const noexcept;

        void clear() noexcept;

        void resize(size_type _count, const value_type &value);
        void resize(size_type _count);

        void swap(LinkedList &other) noexcept;
    };

};

#include "../src/linked_list.tpp"