/**
 * @brief Merge Sort
 *
 * Copyright (c) 2017 Kevin Morris
**/
#ifndef MERGE_HPP
#define MERGE_HPP

#include <vector>
#include <utility>
#include <memory>
#include <algorithm>

namespace merge_sort_impl
{
    /**
     * @return New pivot index
    **/

    template<typename T, typename U>
    void copy_range(T& t, U& u, int p, int r)
    {
        auto iter_t = std::begin(t);
        std::copy(iter_t + p, iter_t + r, std::begin(u));
    }

    template<typename T, typename U>
    T make_copy(U& u, int p, int r)
    {
        T t(r - p);
        copy_range(u, t, p, r);
        return t;
    }

    template<template<typename, typename...> class Container, typename T>
    void _merge(Container<T>& container, int p, int q, int r)
    {
        const int lhs_size = q - p + 1;
        const int rhs_size = r - q;

        using vector_t = std::vector<T>;

        auto lhs = make_copy<vector_t>(container, p, q + 1);
        auto rhs = make_copy<vector_t>(container, q + 1, r + 1);

        // Merge the array halves back into container
        int i = 0, j = 0, k = p;       
        while(i < lhs_size && j < rhs_size) {
            if(lhs[i] <= rhs[j]) {
                container[k++] = lhs[i++];
            }
            else {
                container[k++] = rhs[j++];
            }
        }

        // Push through the remaining elements
        while(i < lhs_size) {
            container[k++] = lhs[i++];
        }
        while(j < rhs_size) {
            container[k++] = rhs[j++];
        }
    }

    template<template<typename, typename...> class Container, typename T>
    void _divide(Container<T>& container, int p, int r)
    {
        if(p < r) {

            // Get midpoint between p and r
            int q = (p + r) / 2;

            // Recurse lower half
            _divide(container, p, q);

            // Recurse upper half
            _divide(container, q + 1, r);

            // Merge the division together
            /* Note: Since this call occurs after the two divisions, it will
            begin when the stack unrolls @ p >= r */
            _merge(container, p, q, r);
        }
    }
};

template<template<typename, typename...> class Container, typename T>
void merge_sort(Container<T>& container)
{
    // We have nothing to sort
    if(container.size() <= 1)
        return;
    merge_sort_impl::_divide(container, 0, container.size() - 1);
}

#endif /* MERGE_HPP */

