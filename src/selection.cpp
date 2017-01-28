#include "../include/print.hpp"
#include "../include/selection.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v { 6, 3, 19, 2, 32, 24, 1, 15, 12 };
    cout << v << endl;

    selection_sort(v);
    cout << v << endl;
    return 0;
}

