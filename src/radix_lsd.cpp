#include "../include/print.hpp"
#include "../include/radix_lsd.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    std::vector<int> v { 66, 33, 99, 666, 333, 431, 2346, 999 };
    cout << v << endl;

    radix_lsd_sort(v);
    cout << v << endl;
    return 0;
}

