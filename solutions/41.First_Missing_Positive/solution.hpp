/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cmath>
#include <vector>

class Solution {
   public:
    // overloading operator()
    int operator()(std::vector<int>& nums) {
        return firstMissingPositive(nums);
    }

    // function()
    int firstMissingPositive(std::vector<int>& nums) {
        auto size = nums.size();
        for (auto& i : nums) {
            i = i <= 0 ? size + 1 : i;
        }
        int pos{};
        for (auto i : nums) {
            pos = std::abs(i);
            if (pos <= size) {
                nums[pos - 1] = -abs(nums[pos - 1]);
            }
        }
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return size + 1;
    }
};

#endif