#ifndef INSERTION_HPP
#define INSERTION_HPP

#include <utility>

namespace insertion_sort_impl
{
    /**
     * @param container Container we are sorting
     * @param i Current iteration
     * @param target Target location to insert
    **/
    template<typename Container>
    void _insert(Container& container, int current, int target)
    {
        // Save current value
        auto temp = container[current];

        // Shift everything [target .. current - 1] over + 1 position
        auto saved = container[target];
        for(int i = target; i < current; ++i) {
            auto temp = saved;
            saved = container[i + 1];
            container[i + 1] = std::move(temp);
        }
        // Insert current value into the target slot
        container[target] = std::move(temp);
    }

    template<typename Container>
    void _sort(Container& container)
    {
        // For each index in container
        for(int i = 0; i < container.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(container[i] <= container[j]) {
                    _insert(container, i, j);
                }
            }
        }

    }
};

template<typename Container>
void insertion_sort(Container& container)
{
    if(container.size() <= 1)
        return;
    insertion_sort_impl::_sort(container);
}

#endif /* INSERTION_HPP */

