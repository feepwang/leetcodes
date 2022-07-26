/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;
#include <algorithm>
using std::reverse;

class Solution {
   public:
    // overloading operator()
    // int operator()(int i,int j);

    // function()
    vector<int> plusOne(vector<int>& digits) {
        auto beg = digits.crbegin(), end = digits.crend();
        vector<int> result;
        bool mark = true;
        while (beg < end) {
            if (mark) {
                if (*beg == 9) {
                    result.push_back(0);
                    mark = true;
                } else {
                    result.push_back(*beg + 1);
                    mark = false;
                }
            } else
                result.push_back(*beg);
            beg++;
        }
        if (mark) result.push_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif