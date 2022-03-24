#include <iostream>

#include "661.Image_Smoother.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};

    vector<vector<int>> img{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    for (auto v : sol(img)) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}