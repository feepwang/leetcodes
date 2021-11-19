/*
 * Question:
 * Given a 2D matrix matrix, handle multiple queries of the following type:
 *
 * Calculate the sum of the elements of matrix inside the rectangle defined by
 * its upper left corner (row1, col1) and lower right corner (row2, col2).
 * Implement the NumMatrix class:
 *
 * NumMatrix(int[][] matrix) Initializes the object with the integer matrix
 * matrix. int sumRegion(int row1, int col1, int row2, int col2) Returns the sum
 * of the elements of matrix inside the rectangle defined by its upper left
 * corner (row1, col1) and lower right corner (row2, col2).
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class NumMatrix {
   public:
    NumMatrix(std::vector<std::vector<int>>& matrix)
        : sums(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0)) {
        int m = matrix.size(), n = matrix[0].size();

        if (m > 0) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] -
                                         sums[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] -
               sums[row2 + 1][col1] + sums[row1][col1];
    }

   private:
    std::vector<std::vector<int>> sums;
};

}  // namespace lc

#endif