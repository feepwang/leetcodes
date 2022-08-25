/*
 * Question:
 * You are given a 0-indexed 1-dimensional (1D) integer array original, and two
 * integers, m and n. You are tasked with creating a 2-dimensional (2D) array
 * with m rows and n columns using all the elements from original.
 *
 * The elements from indices 0 to n - 1 (inclusive) of original should form the
 * first row of the constructed 2D array, the elements from indices n to 2 * n -
 * 1 (inclusive) should form the second row of the constructed 2D array, and so
 * on.
 *
 * Return an m x n 2D array constructed according to the above procedure, or an
 * empty 2D array if it is impossible.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/convert-1d-array-into-2d-array
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class Solution {
   public:
    std::vector<std::vector<int>> operator()(std::vector<int>& original, int m,
                                             int n) {
        return construct2DArray(original, m, n);
    }

   private:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original,
                                                   int m, int n) {
        std::vector<std::vector<int>> ans;
        if (original.size() != m * n) {
            return ans;
        }
        for (auto it = original.begin(); it != original.end(); it += n) {
            ans.emplace_back(it, it + n);
        }
        return ans;
    }
};

}  // namespace lc

#endif