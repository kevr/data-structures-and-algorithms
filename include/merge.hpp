/**
 * @brief Merge Sort
 *
 * Copyright (c) 2017 Kevin Morris
**/
#ifndef MERGE_HPP
#define MERGE_HPP

#include <utility>
#include <memory>

namespace merge_sort_impl
{
    /**
     * @return New pivot index
    **/
    template<template<typename, typename...> class Container, typename T>
    void _merge(Container<T>& container, int p, int q, int r)
    {
        const int lhs_size = q - p + 1;
        const int rhs_size = r - q;

        T *lhs = new T[lhs_size];
        T *rhs = new T[rhs_size];

        // Just set these up to delete [] memory out of scope
        std::unique_ptr<T[]> lhsPtr(lhs);
        std::unique_ptr<T[]> rhsPtr(rhs);

        // Fill up our array halves
        for(int k = 0, i = p; i <= q; ++i)
            lhs[k++] = container[i];
        for(int k = 0, j = q + 1; j <= r; ++j)
            rhs[k++] = container[j];

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

