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
    int operator()(const string& haystack, const string& needle) {
        return strStr(haystack, needle);
    }

    // function()
    bool check(const string& str1, const size_t& pos, const string& str2) {
        for (size_t i = 0, sz = str2.size(); i < sz; i++) {
            if (str1[pos + i] != str2[i]) return false;
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;

        int pos = 0, max_pos = haystack.size() - needle.size();
        int nd_sz = needle.size();
        while (pos <= max_pos) {
            if (check(haystack, pos, needle)) return pos;
            pos++;
        }
        return -1;
    }
};

#endif