/*
 * Question:
 * Given a string s, return the longest palindromic substring in s.
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <string>
#include <vector>

namespace lc {

class Solution {
   public:
    std::string operator()(const std::string& s) {
        return longestPalindrome(s);
    }

   private:
    std::string longestPalindrome(std::string s) { int n = s.size();
        if (n < 2) return s;

        int maxlen = 1;
        int begin = 0;

        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) dp[i][i] = true;

        //  l 是子串长度, i 是 子字符串左端点
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i < n; ++i) {
                int j = l + i - 1;
                if (j >= n) break;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        //  如果 l - 1 < 3
                        //  一定为 aa 或 aba
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && l > maxlen) {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};

}  // namespace lc

#endif