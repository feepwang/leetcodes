#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "304.Range_Sum_Query_2D-Immutable.hpp"

int main() {
    using std::cout;
    using std::endl;

    std::vector<std::vector<int>> nums{
        {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};

    lc::NumMatrix nm{nums};
    
    //  output
    cout << nm.sumRegion(2, 1, 4, 3) << " " << nm.sumRegion(1, 1, 2, 2) << " "
         << nm.sumRegion(1,2,2,4);
    cout << endl;
}