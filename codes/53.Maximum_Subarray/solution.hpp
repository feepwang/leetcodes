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
    int operator()(vector<int>& nums) { return maxSubArray(nums); }

    // function()
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = 0;
        for (const auto& i : nums) {
            pre = max(pre + i, i);
            ans = max(ans, pre);
        }
        return ans;
    }
};

#endif