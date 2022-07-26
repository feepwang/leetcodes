#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    // print result of solution.
    for (auto i : s(4)) {
        cout << i << endl;
    }
    cout << endl;
}