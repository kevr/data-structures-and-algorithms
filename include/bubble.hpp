#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include <utility>

namespace bubble_sort_impl
{
    template<typename T>
    void swap(T& a, T& b)
    {
        T c = std::move(a);
        a = std::move(b);
        b = std::move(c);
    }

    template<typename Container>
    void _quick_pass(Container& container, int p, int r)
    {
        for(int i = p; i < r; ++i) {
            if(container[i] > container[i + 1]) {
                swap(container[i], container[i + 1]);
            }
        }
    }

    /** Note: We use a bit of an optimization by calling _quick_pass
    when we find the first instance of an unsorted array. */
    template<typename Container>
    void _sort(Container& container)
    {
        bool not_done = true;
        while(not_done) {
            not_done = false;
            for(int i = 0; i < container.size() - 1; ++i) {
                if(container[i] > container[i + 1]) {
                    not_done = true;
                    _quick_pass(container, i, container.size() - 1);
                    break;
                }
            }
        }
    }
};

/** @brief Just a terrible sort function **/
template<typename Container>
void bubble_sort(Container& container)
{
    if(container.size() <= 1)
        return;
    bubble_sort_impl::_sort(container);
}

#endif /* BUBBLE_HPP */

