#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "594.Longest_Harmonious_Subsequence.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    std::vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};
    
    //  output
    cout << s(nums);
    cout << endl;
}