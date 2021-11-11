#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "119.Pascal's_Triangle_Ⅱ.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    // print result of solution.
    for (auto i : s(3)) {
        cout << i << " ";
    }

    cout << endl;
}