/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::max;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& nums) { return getMaxLen(nums); }

    // function()
    int getMaxLen(vector<int>& nums) {
        int result{}, pos{}, neg{};
        for (auto i : nums) {
            if (i > 0) {
                ++pos;
                neg = neg ? neg + 1 : 0;
            } else if (i < 0) {
                int tmp = neg;
                neg = pos + 1;
                pos = tmp ? tmp + 1 : 0;
            } else {
                pos = 0;
                neg = 0;
            }
            result = max(result, pos);
        }
        return result;
    }
};

#endif