#include <iostream>

#include <442.Find_All_Duplicates_in_an_Array.hpp>

int main() {
    using namespace std;

    lc::Solution sol{};

    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};

    for(auto i : sol(nums)) {
        cout << i << " ";
    }
    cout << endl;
}