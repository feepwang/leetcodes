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
    string operator()(int columnNumber) { return convertToTitle(columnNumber); }

    // function()
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber--) {
            result += 'A' + columnNumber % 26;
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif