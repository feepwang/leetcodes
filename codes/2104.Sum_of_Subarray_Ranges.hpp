/*
 * Question:
 * 给你一个整数数组 nums 。nums 中，子数组的 范围
 * 是子数组中最大元素和最小元素的差值。
 *
 * 返回 nums 中 所有 子数组范围的 和 。
 *
 * 子数组是数组中一个连续 非空 的元素序列。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/sum-of-subarray-ranges
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stack>
#include <vector>

namespace lc {

class Solution {
   public:
    long long operator()(std::vector<int>& nums) {
        return subArrayRanges(nums);
    }

   private:
    long long subArrayRanges(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        std::stack<int> minStack, maxStack;
        for (int i = 0; i < n; i++) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
                minStack.pop();
            }
            minLeft[i] = minStack.empty() ? -1 : minStack.top();
            minStack.push(i);

            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) {
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.push(i);
        }
        minStack = std::stack<int>();
        maxStack = std::stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!minStack.empty() && nums[minStack.top()] >= nums[i]) {
                minStack.pop();
            }
            minRight[i] = minStack.empty() ? n : minStack.top();
            minStack.push(i);

            while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? n : maxStack.top();
            maxStack.push(i);
        }

        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < n; i++) {
            sumMax += static_cast<long long>(maxRight[i] - i) *
                      (i - maxLeft[i]) * nums[i];
            sumMin += static_cast<long long>(minRight[i] - i) *
                      (i - minLeft[i]) * nums[i];
        }
        return sumMax - sumMin;
    }
};

}  // namespace lc
