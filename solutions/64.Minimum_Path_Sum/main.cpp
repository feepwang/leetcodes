#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<vector<int>> grid{{1, 2}, {1, 1}};

    // print result of solution.
    cout << s(grid) << endl;
    cout << endl;
}