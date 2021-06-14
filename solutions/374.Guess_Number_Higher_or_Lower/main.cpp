#include <iostream>

#include "solution.hpp"

int guess(int n) {
    if (n == 6)
        return 0;
    else if (n > 6)
        return 1;
    else
        return -1;
}

int main() {
    using namespace std;
    Solution s;

    // print result of solution.
    cout << s(10) << endl;
    cout << endl;
}