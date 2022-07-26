#include <iostream>
#include <vector>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    std::vector<int> nums{5, 1, 3};

    // print result of solution.
    cout << s(nums, 3);
    cout << endl;
}