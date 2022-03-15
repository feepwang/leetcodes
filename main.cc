#include <iostream>

#include "393.UTF-8_Validation.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};
    std::vector<int> data{197, 130, 1};

    if (sol(data)) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;
    cout << endl;
}