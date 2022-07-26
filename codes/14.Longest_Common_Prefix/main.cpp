#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;

    // print result of solution.
    vector<string> strs{"flower", "flow", "flight"};
    cout << s(strs) << endl;
    cout << endl;
}