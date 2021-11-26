/*
 * Question:
 * Given a string s, find the longest palindromic subsequence's length in s.
 *
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/longest-palindromic-subsequence
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <string>
#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(const std::string& s) { return longestPalindromeSubseq(s); }

   private:
    int longestPalindromeSubseq(std::string s) {
        int n = s.length();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            char c1 = s[i];
            for (int j = i + 1; j < n; ++j) {
                char c2 = s[j];
                if (c1 == c2)
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    //  ��� s[i]!=s[j],dp[i][j]
                    //  ���ִ��е������������б�Ȼ��ͬʱ������˵�Ͷ˵�
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

}  // namespace lc

#endif