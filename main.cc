#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "2022.Convert_1D_Array_Into_2D_Array.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;
    std::vector<int> nums{1, 2, 3, 4};

    //  output
    for (const auto& vec : s(nums, 2, 2)) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}