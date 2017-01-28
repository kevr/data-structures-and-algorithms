#ifndef SELECTION_HPP
#define SELECTION_HPP

#include <utility>

namespace selection_sort_impl
{
    template<typename T>
    void swap(T& a, T& b)
    {
        T c = std::move(a);
        a = std::move(b);
        b = std::move(c);
    }

    template<typename Container>
    int _min(Container& container, int p, int r)
    {
        auto min = container[p];
        int idx = p;
        for(int i = p + 1; i < r; ++i) {
            if(container[i] < min) {
                min = container[i];
                idx = i;
            }
        }
        return idx;
    }

    template<typename Container>
    void _sort(Container& container)
    {
        // For each index in container
        for(int i = 0; i < container.size(); ++i) {
            auto min = _min(container, i, container.size());
            swap(container[i], container[min]);
        }

    }
};

template<typename Container>
void selection_sort(Container& container)
{
    if(container.size() <= 1)
        return;
    selection_sort_impl::_sort(container);
}

#endif /* SELECTION_HPP */

