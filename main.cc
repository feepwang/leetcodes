#include <iostream>

#include "2100.Find_Good_Days_to_Rob_the_Bank.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};
    std::vector<int> security{5, 3, 3, 3, 5, 6, 2};

    for (auto i : sol(security, 2)) {
        cout << i << " ";
    }
    cout << endl;
}