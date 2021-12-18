/*
 * Question:
 * Given an array of distinct integers nums and a target integer target, return
 * the number of possible combinations that add up to target.
 *
 * The answer is guaranteed to fit in a 32-bit integer.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/combination-sum-iv
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>
#include <climits>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<int>& nums, int target) {
        return combinationSum4(nums, target);
    }

   private:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int& num : nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};

}  // namespace lc

#endif