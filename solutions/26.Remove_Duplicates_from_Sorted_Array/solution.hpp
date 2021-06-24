/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& nums) { return removeDuplicates(nums); }

    // function()
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        size_t i = 0;
        for (size_t j = 1, sz = nums.size(); j < sz; j++)
            if (nums[i] != nums[j]) nums[++i] = nums[j];
        return i + 1;
    }
};

#endif