/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>

class Solution {
   public:
    // overloading operator()
    int operator()(std::vector<int>& nums, const int& target) {
        return search(nums, target);
    }

    // function()
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size(), pivot = right / 2;
        if (target == nums[0]) {
            return 0;
        }
        if (target == nums[right - 1]) {
            return right - 1;
        }
        if (right == 1) {
            return -1;
        }
        while (nums[pivot] != target && left < right) {
            if (target < nums[left] && target > nums[right - 1]) {
                return -1;
            } else if (nums[left] < nums[pivot]) {
                if (target < nums[pivot] && target > nums[left]) {
                    right = pivot;
                } else {
                    left = pivot;
                }
            } else {
                if (target > nums[pivot] && target <= nums[right - 1]) {
                    // if (target == nums[right - 1]) return right - 1;
                    left = pivot;
                } else {
                    right = pivot;
                }
            }
            pivot = left + (right - left) / 2;
        }
        if (left >= right) return -1;
        return pivot;
    }
};
#endif