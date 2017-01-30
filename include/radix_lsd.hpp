#ifndef RADIX_LSD_HPP
#define RADIX_LSD_HPP

#include <cmath>
#include <vector>
#include <array>

namespace radix_lsd_impl
{
    template<template<typename, typename...> class C, typename T>
    int _count(C<T>& container)
    {
        int figs = 0;
        for(auto& value : container) {
            int fig = int(log10(value)) + 1;
            if(fig > figs)
                figs = fig;
        }
        return figs;
    }

    template<template<typename, typename...> class C, typename T>
    void _pass(C<T>& container, int position, const int n)
    {
        if(position > n)
            return;

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

        int k = 0;
        for(auto& bucket : buckets) {
            for(auto& item : bucket) {
                container[k++] = item;
            }
        }

        // Do another pass with position + 1
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
    if(container.size() <= 1)
        // Already sorted
        return;
    radix_lsd_impl::_sort(container);
}

#endif /* RADIX_LSD_HPP */

