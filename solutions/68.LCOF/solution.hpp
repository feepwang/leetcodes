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
    int operator()(vector<int>& nums, const int& target) {
        return searchInsert(nums, target);
    }

    // function()
    int searchInsert(vector<int>& nums, int target) {
        size_t left = 0, right = nums.size(), pivot = right / 2;

        while (left < right) {
            if (nums[pivot] == target) {
                break;
            } else if (nums[pivot] > target) {
                right = pivot;
            } else {
                left = pivot + 1;
            }
            pivot = left + (right - left) / 2;
        }
        return pivot;
    }
};

#endif