#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "118.Pascal's_Triangle.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    // print result of solution.
    for (const auto& veci : s(5)) {
        for (auto i : veci) {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl;
}