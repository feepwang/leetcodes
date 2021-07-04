/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
using std::string;
#include <stack>
using std::stack;
#include <unordered_map>
using std::unordered_map;

class Solution {
   public:
    // overloading operator()
    bool operator()(const string& s) { return isValid(s); }

    // function()
    bool isValid(string s) {
        if (s.size() % 2) return false;

        stack<char> stk;
        unordered_map<char, char> match{{')', '('}, {'}', '{'}, {']', '['}};
        for (auto c : s) {
            if (match.count(c)) {
                if (stk.size() == 0 || match[c] != stk.top()) return false;
                stk.pop();
            } else
                stk.push(c);
        }
        if (stk.size() != 0) return false;
        return true;
    }
};

#endif