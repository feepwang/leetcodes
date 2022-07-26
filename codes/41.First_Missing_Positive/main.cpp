#include <iostream>
#include <vector>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;
    vector<int> vec{1, 2, 0};

    // print result of solution.
    cout << s(vec);
    cout << endl;
}