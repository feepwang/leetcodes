/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
using std::max;
using std::sort;
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& nums) { return minPairSum(nums); }

    // function()
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0, sz = nums.size(); i < sz / 2; i++)
            sum = max(sum, nums[i] + nums[sz - 1 - i]);
        return sum;
    }
};

#endif