/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;
#include <string>
using std::string;

class Solution {
   public:
    // overloading operator()
    string operator()(vector<string>& strs) {
        return longestCommonPrefix(strs);
    }

    // function()
    string compare(string& str1, string& str2) {
        size_t i = 0, j = std::min(str1.size(), str2.size());
        while (i < j) {
            if (str1[i] != str2[i]) break;
            i++;
        }
        return str1.substr(i + 1);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        string result = strs[0];
        for (auto s : strs) {
            result = compare(result, s);
        }
        return result;
    }
};

#endif