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
    bool operator()(const string& s, const string& t) {
        return backspaceCompare(s, t);
    }

    // function()
    string remake(string& str) {
        auto beg = str.begin(), end = str.end(), stillbeg = beg;
        string::iterator ptr = beg;
        while (ptr != end) {
            if (*ptr == '#') {
                if (beg != stillbeg) beg--;
            } else
                *beg++ = *ptr;
            ptr++;
        }
        return str.substr(0, beg - str.begin());
    }

    bool backspaceCompare(string s, string t) {
        s = remake(s), t = remake(t);
        return s == t ? true : false;
    }
};

#endif