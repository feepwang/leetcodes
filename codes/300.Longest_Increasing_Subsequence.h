/*
 * Question:
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 * A subsequence is a sequence that can be derived from an array by deleting
 * some or no elements without changing the order of the remaining elements. For
 * example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>
#include <algorithm>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<int>& nums) { return lengthOfLIS(nums); }

   private:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size());
        for (std::size_t i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (std::size_t j = 0; j < i; ++j)
                if (nums[j] < nums[i]) dp[i] = std::max(dp[i], dp[j] + 1);
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

}  // namespace lc

#endif