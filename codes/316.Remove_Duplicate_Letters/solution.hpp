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
    string operator()(const string& s) { return removeDuplicateLetters(s); }

    // function()
    string removeDuplicateLetters(string s) {
        string stk;
        for (size_t i = 0; i < s.size(); ++i) {
            if (stk.find(s[i]) != string::npos) continue;
            while (!stk.empty() && stk.back() > s[i] &&
                   s.find(stk.back(), i) != string::npos)
                stk.pop_back();
            stk.push_back(s[i]);
        }
        return stk;
    }
};

#endif