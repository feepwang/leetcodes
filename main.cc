#include <553.Optimal_Division.hpp>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    lc::Solution sol{};

    std::vector<int> nums{1000, 100, 10, 2};

    cout << sol(nums);
    cout << endl;
}