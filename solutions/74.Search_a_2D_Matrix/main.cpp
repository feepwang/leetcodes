#include <iostream>
#include <vector>

#include "solution.hpp"

int main() {
    using namespace std;
    Solution s;
    vector<vector<int>> matrix{
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    // print result of solution.
    cout << s(matrix, 11);
    cout << endl;
}