#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "1314.Matrix_Block_Sum.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    std::vector<std::vector<int>> t{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    //  output
    for (auto v : s(t, 1)) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    };
    cout << endl;
}