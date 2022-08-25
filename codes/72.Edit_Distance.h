/*
 * Question:
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following three operations permitted on a word:
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/edit-distance
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <algorithm>
#include <string>
#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(const std::string& word1, const std::string& word2) {
        return minDistance(word1, word2);
    }

   private:
    int minDistance(std::string word1, std::string word2) {
        auto m = word1.size(), n = word2.size();
        if (m * n == 0) return m + n;

        //int dp[m + 1][n + 1];
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;

        int left{}, down{}, left_down{};
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                left = dp[i - 1][j] + 1;
                down = dp[i][j - 1] + 1;
                left_down = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                dp[i][j] = std::min(left, std::min(down, left_down));
            }
        }

        return dp[m][n];
    }
};

}  // namespace lc

#endif