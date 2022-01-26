#include <iostream>

#include "2013.Detect_Squares.hpp"

int main() {
    using namespace std;

    lc::DetectSqueares ds{};

    ds.add({3, 10});
    ds.add({11, 2});
    ds.add({3, 2});
    cout << ds.count({11, 10}) << endl;
    cout << ds.count({14, 8}) << endl;
    ds.add({11, 2});
    cout << ds.count({11, 10}) << endl;
}