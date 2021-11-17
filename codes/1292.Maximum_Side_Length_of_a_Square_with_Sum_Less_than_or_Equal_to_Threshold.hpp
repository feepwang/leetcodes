/*
 * Question:
 * Given a m x n matrix mat and an integer threshold. Return the maximum
 * side-length of a square with a sum less than or equal to threshold or return
 * 0 if there is no such square.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<std::vector<int>>& mat, int threshold) {
        return maxSideLength(mat, threshold);
    }

   private:
    int getRect(const std::vector<std::vector<int>>& p, int x1, int y1, int x2,
                int y2) {
        return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
    }

    int maxSideLength(std::vector<std::vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::vector<int>> p(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] +
                          mat[i - 1][j - 1];
            }
        }
        int r = std::min(m, n), ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int c = ans + 1; c <= r; ++c) {
                    if (i + c - 1 <= m && j + c - 1 <= n &&
                        getRect(p, i, j, i + c - 1, j + c - 1) <= threshold) {
                        ++ans;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

}  // namespace lc

#endif