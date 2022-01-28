#include <iostream>
#include <vector>

#include "1996.The_Number_of_Weak_Characters_in_the_Game.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};

    std::vector<std::vector<int>> properties{{5, 5}, {6, 3}, {3, 6}};

    cout << sol(properties);
    cout << endl;
}