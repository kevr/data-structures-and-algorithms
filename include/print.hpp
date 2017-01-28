#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << '[';
    for(std::size_t i = 0; i < v.size() - 1; ++i)
        os << v[i] << ", ";
    if(v.size())
        os << v.back() << ']';
    return os;
}

#endif /* PRINT_HPP */
