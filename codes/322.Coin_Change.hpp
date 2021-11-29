/*
 * Question:
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/coin-change
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <algorithm>
#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<int>& coins, int amount) {
        return coinChange(coins, amount);
    }

   private:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < *std::min_element(coins.begin(), coins.end())) return -1;

        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                int tmp = coins[j];
                if (tmp <= i) {
                    int val = dp[i - tmp] + 1;
                    if (val < dp[i])
                        dp[i] = val;
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

}  // namespace lc

#endif