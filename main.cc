#include <iostream>

#include "954.Array_of_Double_Pairs.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};

    std::vector<int> arr{3, 1, 3, 6};
    if (sol(arr))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << endl;
}