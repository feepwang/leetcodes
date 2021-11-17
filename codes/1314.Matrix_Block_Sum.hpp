/*
 * Question:
 * Given a m x n matrix mat and an integer k, return a matrix answer where each
 * answer[i][j] is the sum of all elements mat[r][c] for:
 *
 * i - k <= r <= i + k,
 * j - k <= c <= j + k, and
 * (r, c) is a valid position in the matrix.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/matrix-block-sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class Solution {
   public:
    std::vector<std::vector<int>> operator()(std::vector<std::vector<int>>& mat,
                                             int k) {
        return matrixBlockSum(mat, k);
    }

   private:
    int get(const std::vector<std::vector<int>>& pre, int m, int n, int x,
            int y) {
        x = std::max(std::min(x, m), 0);
        y = std::max(std::min(y, n), 0);
        return pre[x][y];
    }

    std::vector<std::vector<int>> matrixBlockSum(
        std::vector<std::vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::vector<int>> p(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] +
                          mat[i - 1][j - 1];
            }
        }
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = get(p, m, n, i + k + 1, j + k + 1) -
                            get(p, m, n, i - k, j + k + 1) -
                            get(p, m, n, i + k + 1, j - k) +
                            get(p, m, n, i - k, j - k);
            }
        }
        return ans;
    }
};

}  // namespace lc

#endif