#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "1292.Maximum_Side_Length_of_a_Square_with_Sum_Less_than_or_Equal_to_Threshold.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    std::vector<std::vector<int>> t{
        {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};

    //  output
    cout << s(t, 4);
    cout << endl;
}