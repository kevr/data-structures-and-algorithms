#include "../include/print.hpp"
#include "../include/bubble.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> v { 6, 3, 9, 12, 1, 22, 15, 19 };
    cout << v << endl;

    bubble_sort(v);
    cout << v << endl;
    return 0;
}

