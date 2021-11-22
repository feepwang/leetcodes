#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "384.Shuffle_an_Array.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s({1, 2, 3});

    //  output
    std::cout << s;
    s.shuffle();
    std::cout << s;
    s.reset();
    std::cout << s;
    s.shuffle();
    std::cout << s;
    cout << endl;
}