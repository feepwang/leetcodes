/*
 * Question
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/trapping-rain-water
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>

class Solution {
   public:
    // overloading operator()
    int operator()(std::vector<int>& height) { return trap(height); }

    // function()
    int trap(std::vector<int>& height) {
        // if (height.empty()) return 0;
        // auto sz = height.size();

        // std::vector<int> left(sz, 0), right(sz, 0);

        // left[0] = height[0];
        // for (int i = 1; i < sz; ++i) {
        //     left[i] = std::max(left[i - 1], height[i]);
        // }

        // right[sz - 1] = height[sz - 1];
        // for (int i = sz - 2; i >= 0; --i) {
        //     right[i] = std::max(right[i + 1], height[i]);
        // }

        // int result = 0;
        // for (int i = 0; i < sz; ++i) {
        //     result += std::min(left[i], right[i]) - height[i];
        // }

        // return result;

        if (height.empty()) return 0;
        int sz = height.size();
        int left = 0, right = sz - 1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    res += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    res += right_max - height[right];
                }
                right--;
            }
        }
        return res;
    }
};

#endif