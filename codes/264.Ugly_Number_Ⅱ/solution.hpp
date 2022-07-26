/*
 * Question
 * An ugly number is a positive integer whose prime factors are limited to 2, 3,
 * and 5.
 *
 * Given an integer n, return the nth ugly number.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/ugly-number-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>

class Solution {
   public:
    // overloading operator()
    int operator()(int n) { return nthUglyNumber(n); }

    // function()
    int nthUglyNumber(int n) {
        std::vector<int> dp(n + 1);

        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2, num2, num3, num5; i <= n; ++i) {
            num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = std::min(num2, std::min(num3, num5));
            if (dp[i] == num2) ++p2;
            if (dp[i] == num3) ++p3;
            if (dp[i] == num5) ++p5;
        }
        return dp[n];
    }
};

#endif