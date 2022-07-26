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
    int operator()(vector<int>& nums, int val) {
        return removeElement(nums, val);
    }

    // function()
    int removeElement(vector<int>& nums, int val) {
        auto sz = nums.size();
        size_t i = 0;
        for (size_t j = 0; j < sz; j++) {
            if (nums[j] != val) nums[i++] = nums[j];
        }
        return i;
    }
};

#endif