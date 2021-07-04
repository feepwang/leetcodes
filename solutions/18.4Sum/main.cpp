#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<int> nums{1, 0, -1, 0, -2, 2};

    // print result of solution.
    auto result = s(nums, 0);

    for (auto v : result) {
        for (auto i : v) cout << i << ' ';
        cout << endl;
    }
    cout << endl;
}