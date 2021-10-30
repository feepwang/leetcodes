/*
 * Question
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and
 * uses only constant extra space.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/single-number-iii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <climits>
#include <vector>

class Solution {
   public:
    // overloading operator()
    std::vector<int> operator()(std::vector<int>& nums) {
        return singleNumber(nums);
    }

    // function()
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int xor_{};
        for (auto i : nums) {
            xor_ ^= i;
        }
        int mask = xor_ == INT_MIN ? xor_ : xor_ & (-xor_);
        int val1{}, val2{};
        for (auto i : nums) {
            if (i & mask) {
                val1 ^= i;
            } else {
                val2 ^= i;
            }
        }
        return {val1, val2};
    }
};

#endif