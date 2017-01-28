#include "../../include/datastruct/list.hpp"
#include <iostream>
#include <cassert>
using namespace std;

int main(int argc, char *argv[])
{
    datastruct::list<int> v;

    v.emplace_back(2);
    assert(v.size() == 1);
    assert(v.peek() == 2);

    v.push_back(6);
    assert(v.peek() == 2);
    assert(v.size() == 2);
    assert(v[1] == 6);
    assert(v[0] == 2);
    v.erase(1);
    assert(v.size() == 1);
    assert(v.peek() == 2);
    v.pop();
    assert(v.size() == 0);
    return 0;
}

