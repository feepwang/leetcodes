/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <algorithm>
#include <string>
#include <vector>

class Solution {
   public:
    // overloading operator()
    int operator()(const std::string& text1, const std::string& text2) {
        return longestCommonSubsequence(text1, text2);
    }

    // function()
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length(), n = text2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; ++j) {
                char c2 = text2.at(j - 1);
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

#endif