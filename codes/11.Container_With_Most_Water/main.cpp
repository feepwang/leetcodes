#include <iostream>
#include <vector>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};

    // print result of solution.
    cout << s(vec) << endl;
    cout << "end." << endl;
}