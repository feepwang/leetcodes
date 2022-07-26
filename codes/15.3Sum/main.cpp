#include <iostream>
#include <vector>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<int> nums{1, 0, 1, 2, -1, -4};

    for (auto a : s(nums)) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }

    // print result of solution.
    cout << endl;
}