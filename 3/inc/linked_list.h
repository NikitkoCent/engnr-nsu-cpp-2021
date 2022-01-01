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
        using size_type = std::uint32_t;
        using difference_type = std::ptrdiff_t;
        using reference = T &;
        using const_reference = const T &;
        using pointer = T *;
        using const_pointer = const T *;

        using iterator = Iterator<T, false>;
        using const_iterator = ConstIterator<T, false>;
        using reverse_iterator = Iterator<T, true>;
        using const_reverse_iterator = ConstIterator<T, true>;

    private:
        size_type count;
        BaseNode<T> *head;
        BaseNode<T> *tail;

    public:
        LinkedList() : count(0), head(new BaseNode<T>()), tail(new BaseNode<T>())
        {
            head->next = tail;
            tail->prev = head;
        }

        LinkedList(const LinkedList &other) : LinkedList<T>()
        {
            for (const auto &item : other)
                push_back(item);
        }

        LinkedList(LinkedList &&other)
        {

            this->count = other.count;
            other.count = 0;
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
            for (; first != last; ++first)
                push_back(*first);
        }

        LinkedList(std::initializer_list<T> init) : LinkedList<T>()
        {
            for (const auto &item : init)
                push_back(item);
        }
        ~LinkedList()
        {
            clear();
            delete (head);
            delete (tail);
        }

    public:
        LinkedList &operator=(const LinkedList &other);
        LinkedList &operator=(LinkedList &&other);
        LinkedList &operator=(std::initializer_list<T> ilist);

        void assign(size_type _count, const T &value);
        template <typename InputIt>
        void assign(InputIt first, InputIt last);
        void assign(std::initializer_list<T> ilist);

    public:
        reference front() { return head->next->getData(); }

        const_reference front() const { return *head->next->getData(); }

        reference back() { return tail->prev->getData(); }

        const_reference back() const { return tail->prev->getData(); }

    public:
        iterator begin() noexcept { return iterator(*head->next); }

        const_iterator begin() const noexcept { return const_iterator(*head->next); }

        const_iterator cbegin() const noexcept { return const_iterator(*head->next); }

        iterator end() noexcept { return iterator(*tail); }

        const_iterator end() const noexcept { return const_iterator(*tail); }

        const_iterator cend() const noexcept { return const_iterator(*tail); }

    public:
        reverse_iterator rbegin() noexcept { return reverse_iterator(*tail->prev); }

        const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(*tail->prev); }

        const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(*tail->prev); }

        reverse_iterator rend() noexcept { return reverse_iterator(*head); }

        const_reverse_iterator rend() const noexcept { return const_reverse_iterator(*head); }

        const_reverse_iterator crend() const noexcept { return const_reverse_iterator(*head); }

    public:
        size_type size() const noexcept;
        bool empty() const noexcept;

    public:
        iterator insert(const_iterator pos, const T &value);
        iterator insert(const_iterator pos, T &&value);
        iterator insert(const_iterator pos, size_type _count, const T &value);

        template <typename InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last);
        iterator insert(const_iterator pos, std::initializer_list<T> ilist);

        void push_front(const T &value);
        void push_front(T &&value);

        void push_back(const T &value);
        void push_back(T &&value);

    private:
        void push_back();
        void push_front();

    public:
        iterator erase(const_iterator pos);
        iterator erase(const_iterator first, const_iterator last);

        void pop_back();
        void pop_front();

    public:
        bool operator==(const LinkedList &);
        bool operator!=(const LinkedList &);

    public:
        void sort();
        template <typename Compare>
        void sort(Compare comp);

    private:
        template <typename InputIt, typename Compare>
        void merge_sort(InputIt beg, InputIt end, Compare comp);

        template <typename InputIt, typename Compare>
        void merge(InputIt beg, InputIt mid,
                   InputIt end, Compare comp);

    public:
        size_type unique();
        template <typename BinaryPredicate>
        size_type unique(BinaryPredicate p);

        void reverse() noexcept;

        size_type remove(const T &value);
        template <typename UnaryPredicate>
        size_type remove_if(UnaryPredicate p);

    public:
        void print() const;
        void clear();

        void resize(size_type _count, const value_type &value);
        void resize(size_type _count);

        void swap(LinkedList &other) noexcept;
    };

}

#include "../src/linked_list.tpp"