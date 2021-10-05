#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;
    vector<int> vec{1, 3, 5, 6};
    // print result of solution.
    cout << s(vec, 2);
    cout << endl;
}