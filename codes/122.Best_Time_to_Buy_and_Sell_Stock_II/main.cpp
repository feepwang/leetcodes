#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<int> prices{7, 1, 5, 3, 6, 4};

    // print result of solution.
    cout << s(prices) << endl;
    cout << endl;
}