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
    bool operator()(vector<int>& nums) { return canJump(nums); }

    // function()
    bool canJump(vector<int>& nums) {
        auto sz = nums.size();

        for (int i = 0, right = 0; i < sz; ++i) {
            if (i > right) return false;
            right = max(right, i + nums[i]);
        }
        return true;
    }
};

#endif