#include <iostream>
#include <vector>

#include "1765.Map_of_Highest_Peak.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};

    std::vector<std::vector<int>> isWater{{0, 1}, {0, 0}};

    for (const auto& nums : sol(isWater)) {
        for (auto i : nums) {
            cout << i << ' ';
        }
        cout << endl;
    }
    cout << endl;
}