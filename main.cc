#include <iostream>

#include "728.Self_Dividing_Numbers.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};

    for (auto i : sol(1, 22)) {
        cout << i << ' ';
    }
    cout << endl;
}