#include <iostream>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    // print result of solution.
    if (s("ab#c", "ad#c"))
        cout << "true." << endl;
    else
        cout << "false." << endl;
    cout << endl;
}