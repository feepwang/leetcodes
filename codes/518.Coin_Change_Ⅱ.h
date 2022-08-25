/*
 * Question:
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the number of combinations that make up that amount. If that amount of
 * money cannot be made up by any combination of the coins, return 0.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * The answer is guaranteed to fit into a signed 32-bit integer.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/coin-change-2
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <algorithm>
#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(int amount, std::vector<int>& coins) {
        return change(amount, coins);
    }

   private:
    int change(int amount, std::vector<int>& coins) {
        if (amount < *std::min_element(coins.cbegin(), coins.cend())) return 0;

        std::vector<int> dp(amount + 1);
        dp[0] = 1;

        for (int& coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

}  // namespace lc

#endif