/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cstddef>
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<int>& nums) { return removeDuplicates(nums); }

    // function()
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        size_t i = 0, sz = nums.size();
        for (size_t j = 0; j < sz - 2; j++) {
            if (nums[j] != nums[j + 2]) nums[i++] = nums[j];
        }
        nums[i++] = nums[sz - 2];
        nums[i++] = nums[sz - 1];
        return i;
    }
};

#endif