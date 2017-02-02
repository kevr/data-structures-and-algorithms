#ifndef DATASTRUCT_QUEUE_HPP
#define DATASTRUCT_QUEUE_HPP

#include "list.hpp"
#include <utility>

namespace datastruct
{
    template<typename T>
    class queue
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

        /* Push first-in item */
        queue& push(T value)
        {
            _list.push_back(std::move(value));
            return *this;
        }

        /* Next value to be popped from the queue */
        const T& upcoming() const
        {
            return _list[0];
        }

        /* The latest value added to the queue */
        const T& back() const
        {
            return _list[_list.size() - 1];
        }

        /* Pop first-in item out */
        T pop()
        {
            T v { std::move(_list[0]) };
            _list.pop();
            return v;
        }

    };
};

#endif /* DATASTRUCT_QUEUE_HPP */

