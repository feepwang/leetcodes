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
    int operator()(vector<int>& nums) { return rob(nums); }

    // function()
    int rob(vector<int>& nums) {
        auto sz = nums.size();
        if (sz == 1) return nums[0];
        auto val1 = nums[0], val2 = max(val1, nums[1]), tmp = 0;
        for (int i = 2; i < sz; i++) {
            tmp = val2;
            val2 = max(val1 + nums[i], val2);
            val1 = tmp;
        }
        return val2;
    }
};

#endif