#include <iostream>

#include "2028.Find_Missing_Observations.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};
    vector<int> rolls{3, 2, 4, 3};

    for (auto& i : sol(rolls, 4, 2)) {
        cout << i << ' ';
    }
    cout << endl;
}