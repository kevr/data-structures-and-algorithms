#include "../include/print.hpp"
#include "../include/radix_lsd.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    std::vector<int> v { 6, 20, 30, 12, 10, 5, 2, 200, 212 };
    cout << v << endl;

    radix_lsd_sort(v);
    cout << v << endl;
    return 0;
}

