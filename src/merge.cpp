#include "../include/print.hpp"
#include "../include/merge.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v { 6, 2, 3, 9, 12, 16, 1, 12, 4, 20, 19 };
    cout << v << endl;

    merge_sort(v);
    cout << v << endl;
    return 0;
}

