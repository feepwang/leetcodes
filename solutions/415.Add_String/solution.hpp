/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::reverse;
#include <string>
using std::string;

class Solution {
   public:
    // overloading operator()
    string operator()(const string& num1, const string& num2) {
        return addStrings(num1, num2);
    }

    // function()
    string addStrings(string num1, string num2) {
        string result{};

        reverse(result.begin(), result.end());
        return result;
    }
};

#endif