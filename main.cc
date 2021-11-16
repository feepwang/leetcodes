#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "931.Minimum_Falling_Path_Sum.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    std::vector<std::vector<int>> t {
        {2, 1, 3}, {6, 5, 4}, { 7, 8, 9 }
    };


    //  print result of solution.
    //  cout << s(3);
    cout << s(t);
    cout << endl;
}