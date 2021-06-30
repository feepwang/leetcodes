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
    string operator()(const int& n) { return countAndSay(n); }

    // function()
    string countAndSay(int n) {
        string result = "1";
        while (--n) {
            const string last = result;
            result = "";
            char c = last[0];
            int count = 0;
            for (auto a : last) {
                if (c != a) {
                    result += std::to_string(count) + c;
                    count = 0;
                    c = a;
                }
                count++;
            }
            result += std::to_string(count) + c;
        }
        return result;
    }
};

#endif