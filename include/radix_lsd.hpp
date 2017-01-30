#ifndef RADIX_LSD_HPP
#define RADIX_LSD_HPP

#include <cmath>
#include <vector>
#include <array>

namespace radix_lsd_impl
{
    // Get the max key length in the container
    template<template<typename, typename...> class C, typename T>
    int _count(C<T>& container)
    {
        int max = 0;
        for(auto& value : container) {
            int current = int(log10(value)) + 1;
            if(current > max)
                max = current;
        }
        return max;
    }

    // A single pass on a specific digit position
    template<template<typename, typename...> class C, typename T>
    void _pass(C<T>& container, int position, const int n)
    {
        // Should we not be here? (Base case)
        if(position > n)
            return; // Then end this recursion

        // Allocate some buckets
        std::array<std::vector<T>, 10> buckets;

        // At pos = 1, 10^1-1 => 10^0 => 1
        // At pos = 2, 10^2-2 => 10^1 => 10
        // ...
        auto divisor = pow(10, position - 1);
        for(int i = 0; i < container.size(); ++i) {
            const int digit = int(container[i] / divisor) % 10;
            buckets[digit].emplace_back(container[i]);
        }

        // Reinsert buckets [0..9] into the original container
        int k = 0;
        for(auto& bucket : buckets) {
            for(auto& item : bucket) {
                container[k++] = item;
            }
        }

        // Try another pass with position + 1
        return _pass(container, position + 1, n);
    }

    template<template<typename, typename...> class C, typename T>
    void _sort(C<T>& container)
    {
        // Get n max digits to check
        int n = _count(container);
        // Start pass recursion
        _pass(container, 1, n);
    }

};

template<template<typename, typename...> class C, typename T>
void radix_lsd_sort(C<T>& container)
{
    radix_lsd_impl::_sort(container);
}

#endif /* RADIX_LSD_HPP */

