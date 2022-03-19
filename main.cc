#include <iostream>

#include "720.Longest_Word_in_Dictionary.hpp"

int main() {
    using namespace std;

    lc::Solution sol{};
    vector<string> words{"w", "wo", "wor", "worl", "world"};

    cout << sol(words) << endl;
    cout << endl;
}