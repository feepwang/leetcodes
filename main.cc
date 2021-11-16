#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "120.Triangle.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    std::vector<std::vector<int>> t{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}
    };

    //  print result of solution.
    //  cout << s(3);
    cout << s(t);
    cout << endl;
}