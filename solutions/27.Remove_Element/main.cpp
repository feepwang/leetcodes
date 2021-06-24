#include <iostream>
#include <vector>

#include "solution.hpp"
using std::vector;

int main() {
    using namespace std;
    Solution s;

    vector<int> nums{3, 2, 2, 3};

    // print result of solution.
    nums.resize(s(nums, 3));
    for (auto i : nums) cout << i << ' ';
    cout << endl;
}