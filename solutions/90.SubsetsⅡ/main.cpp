#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;
    vector<int> nums{0};

    // print result of solution.
    for (auto vec : s(nums)) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}