#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};

    // print result of solution.
    cout << s(gas, cost) << endl;
    cout << endl;
}