/*
 * Question:
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 *
 * A falling path starts at any element in the first row and chooses the element
 * in the next row that is either directly below or diagonally left/right.
 * Specifically, the next element from position (row, col) will be (row + 1, col
 * - 1), (row + 1, col), or (row + 1, col + 1).
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/minimum-falling-path-sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>
#include <algorithm>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<std::vector<int>>& matrix) {
        return minFallingPathSum(matrix);
    }

   private:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int sz = matrix.size();
        for (int r = sz - 2; r >= 0; --r) {
            for (int c = 0; c < sz; ++c) {
                int best = matrix[r + 1][c];
                if (c) {
                    best = std::min(best, matrix[r + 1][c - 1]);
                }
                if (c + 1 < sz) {
                    best = std::min(best, matrix[r + 1][c + 1]);
                }
                matrix[r][c] += best;
            }
        }

        int ans = INT_MAX;
        for (int x : matrix[0]) ans = std::min(ans, x);

        return ans;
    }
};

}  // namespace lc

#endif