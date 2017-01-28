/**
 * @brief Quick Sort
 *
 * Copyright (c) 2017 Kevin Morris
**/
#ifndef QUICK_HPP
#define QUICK_HPP

#include <utility>

namespace quick_sort_impl
{

    template<typename T>
    void swap(T& a, T& b)
    {
        T c = std::move(a);
        a = std::move(b);
        b = std::move(c);
    }

    /**
     * @return New pivot index
    **/
    template<typename Container>
    int _partition(Container& container, int p, int r)
    {
        int q = p;
        for(int j = p; j < r; ++j) {
            if(container[j] <= container[r])
                swap(container[j], container[q++]);
        }
        swap(container[r], container[q]);
        return q;
    }

    template<typename Container>
    void _divide(Container& container, int p, int r)
    {
        if(p < r) {
            // Store the pivot as q
            int q = _partition(container, p, r);

            // Recurse the two halves
            _divide(container, p, q - 1);
            _divide(container, q + 1, r);
        }
    }
};

template<typename Container>
void quick_sort(Container& container)
{
    // We have nothing to sort
    if(container.size() <= 1)
        return;

    quick_sort_impl::_divide(container, 0, container.size() - 1);
}

#endif /* QUICK_HPP */

