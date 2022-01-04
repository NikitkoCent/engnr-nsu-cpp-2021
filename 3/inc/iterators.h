#pragma once

#include <iterator>

#include "./node.h"

namespace ns_LLIST
{
    template <typename T>
    class RawIterator
    {
    public:
        using difference_type = ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

    public:
        BaseNode<T> *_curr_ptr;

    public:
        explicit RawIterator(BaseNode<T> &node_ptr) : _curr_ptr(&node_ptr){};
        explicit RawIterator(const BaseNode<T> &node_ptr) : _curr_ptr(&(std::remove_const_t<BaseNode<T> &>(node_ptr))){};

        virtual ~RawIterator() = default;

    public:
        bool operator!=(const RawIterator<T> &it)
        {
            return !(*this == it);
        }

        bool operator==(const RawIterator<T> &it)
        {
            return (_curr_ptr == it._curr_ptr);
        }

    public:
        void swap(RawIterator& it)
        {
            std::swap(_curr_ptr, it._curr_ptr);
        }
    };

    template <typename T, bool isRvrs, typename It>
    class BaseIterator : public RawIterator<T>
    {
    public:
        using RawIterator<T>::_curr_ptr;

        //Forward Iterator
        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<!_isRvrs, It &>
        operator++()
        {
            _curr_ptr = _curr_ptr->next;
            return static_cast<It &>(*this);
        }

        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<!_isRvrs, It>
        operator++(int)
        {
            It result = It(*this->_curr_ptr);
            _curr_ptr = _curr_ptr->next;
            return result;
        }

        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<!_isRvrs, It &>
        operator--()
        {
            _curr_ptr = _curr_ptr->prev;
            return static_cast<It &>(*this);
        }

        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<!_isRvrs, It>
        operator--(int)
        {
            It result = It(*(this->_curr_ptr));
            _curr_ptr = _curr_ptr->prev;
            return result;
        }
        //End Forward Iterator


        //Reverse Iterator
        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<_isRvrs, It &>
        operator++()
        {
            _curr_ptr = _curr_ptr->prev;
            return static_cast<It &>(*this);
        }

        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<_isRvrs, It>
        operator++(int)
        {
            It* result = It(*(this->_curr_ptr));
            _curr_ptr = _curr_ptr->prev;
            return result;
        }

        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<_isRvrs, It &>
        operator--()
        {
            _curr_ptr = _curr_ptr->next;
            return static_cast<It &>(*this);
        }

        template <bool _isRvrs = isRvrs>
        typename std::enable_if_t<_isRvrs, It>
        operator--(int)
        {
            It result = It(*(this->_curr_ptr));
            _curr_ptr = _curr_ptr->next;
            return result;
        }
        //End Reverse Iterator

        It& operator=(const RawIterator<T>& other)
        {
            _curr_ptr = other._curr_ptr;
            return static_cast<It&>(*this);
        }

        It& operator=(const RawIterator<T>&& other)
        {
            _curr_ptr = other._curr_ptr;
            other._curr_ptr = nullptr;
            return static_cast<It&>(*this);
        }

    public:
        explicit BaseIterator(BaseNode<T> &node_ptr) : RawIterator<T>{node_ptr} {};
        explicit BaseIterator(const BaseNode<T> &node_ptr) : RawIterator<T>(node_ptr){};
    };

    template <typename T, bool isRvrs>
    class Iterator : public BaseIterator<T, isRvrs, Iterator<T, isRvrs>>
    {
    public:
        explicit Iterator(const BaseNode<T> &node_ptr) : BaseIterator<T, isRvrs, Iterator>(node_ptr) {}

    public:
        using RawIterator<T>::_curr_ptr;
        T &operator*() { return this->_curr_ptr->getData(); }
        T *operator->() { return &(this->_curr_ptr->getData()); }
    };

    template <typename T, bool isRvrs>
    class ConstIterator : public BaseIterator<T, isRvrs, ConstIterator<T, isRvrs>>
    {
    public:
        explicit ConstIterator(const BaseNode<T> &node_ptr) : BaseIterator<T, isRvrs, ConstIterator>(node_ptr) {}

    public:
        using RawIterator<T>::_curr_ptr;
        const T &operator*() { return this->_curr_ptr->getData(); }
        const T *operator->() { return &(this->_curr_ptr->getData()); }
    };
}