/*
 * Question
 * An integer array is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 *
 * For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic
 * sequences. Given an integer array nums, return the number of arithmetic
 * subarrays of nums.
 *
 * A subarray is a contiguous subsequence of the array.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/arithmetic-slices
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>

class Solution {
   public:
    // overloading operator()
    int operator()(std::vector<int>& nums) {
        return numberOfArithmeticSlices(nums);
    }

    // function()
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int sz = nums.size();
        if (sz < 3) return 0;

        int n = nums.size(), l = 0, ans = 0;
        for (int i = 2, first = nums[0], second = nums[1], cur = nums[2]; i < n;
             first = second, second = cur, cur = nums[++i]) {
            if ((cur - second) == (second - first))
                ans += ++l;
            else
                l = 0;
        }
        return ans;
    }
};
#endif