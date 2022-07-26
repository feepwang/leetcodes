#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<int> nums{1, 1, 2};
    nums.resize(s(nums));
    for (auto i : nums) cout << i << ' ';

    // print result of solution.
    cout << endl;
}