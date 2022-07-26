#include <cstdio>
#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    // print result of solution.
    cout << s(obstacleGrid) << endl;
    cout << endl;
}