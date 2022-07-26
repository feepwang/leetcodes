/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;

class Solution {
   public:
    // overloading operator()
    int operator()(const string& s) { return romanToInt(s); }

    // function()
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> nums{{'M', 1000}, {'D', 500}, {'C', 100},
                                      {'L', 50},   {'X', 10},  {'V', 5},
                                      {'I', 1}};

        for (auto ptr = s.cbegin(), end = s.cend(); ptr < end; ptr++) {
            if (nums[*ptr] < nums[*(ptr + 1)])
                result -= nums[*ptr];
            else
                result += nums[*ptr];
        }
        return result;
    }
};

#endif