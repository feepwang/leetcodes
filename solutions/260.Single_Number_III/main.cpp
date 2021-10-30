#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;
    std::vector<int> nums{1, 2, 1, 3, 2, 5};
    // print result of solution.
    for (auto i : s(nums)) {
        cout << i << " ";
    }
    cout << endl;
}