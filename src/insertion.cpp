#include "../include/print.hpp"
#include "../include/insertion.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v { 6, 3, 19, 2, 32, 24, 1, 15, 12 };
    cout << v << endl;

    insertion_sort(v);
    cout << v << endl;
    return 0;
}

