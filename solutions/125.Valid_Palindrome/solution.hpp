/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
using std::string;

class Solution {
   public:
    // overloading operator()
    bool operator()(const string& s) { return isPalindrome(s); }

    // function()
    bool isPalindrome(string s) {
        string str;
        for (char ch : s) {
            if (isalnum(ch)) {
                str += tolower(ch);
            }
        }
        string str_rev(str.rbegin(), str.rend());
        return str == str_rev;
    }
};

#endif