#ifndef DATASTRUCT_STACK_HPP
#define DATASTRUCT_STACK_HPP

#include "list.hpp"

namespace datastruct
{
    template<typename T>
    class stack
    {
    private:
        list<T> _list;

    public:
        const bool empty() const
        {
            return _list.size() == 0;
        }

        const int size() const
        {
            return _list.size();
        }

        // Push value onto the stack
        stack& push(T value)
        {
            _list.emplace_front(std::move(value));
            return *this;
        }

        const T& peek() const
        {
            return _list[0];
        }

        // Pop value off of the stack
        T pop()
        {
            // Move construct a T with list[0]
            T v { std::move(_list[0]) };
            _list.pop();
            return v;
        }

    };
};

#endif /* DATASTRUCT_STACK_HPP */
