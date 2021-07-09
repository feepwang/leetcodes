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
    int count(const vector<int>& nums) {
        auto sz = nums.size();
        if (sz == 1) return nums[0];

        auto val0 = nums[0], val1 = max(val0, nums[1]), tmp = 0;
        for (int i = 2; i < sz; i++) {
            tmp = val1;
            val1 = max(val0 + nums[i], val1);
            val0 = tmp;
        }
        return val1;
    }

    int rob(vector<int>& nums) {
        auto sz = nums.size();
        if (sz == 1) return nums[0];
        return max(count(vector<int>(nums.begin() + 1, nums.end())),
                   count(vector<int>(nums.begin(), nums.end() - 1)));
    }
};

#endif