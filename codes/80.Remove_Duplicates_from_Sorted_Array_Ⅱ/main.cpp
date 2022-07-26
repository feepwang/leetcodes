#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<int> nums{1, 1, 1, 2, 2, 3};
    nums.resize(s(nums));
    // print result of solution.
    for (auto i : nums) cout << i << ' ';

    cout << endl;
}