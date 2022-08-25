/*
 * Question
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
 * Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/pascals-triangle-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class Solution {
   public:
    //  override operator()
    std::vector<int> operator()(const int& rowIndex) {
        return getRow(rowIndex);
    }

    //  function
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> result{1};

        for (int i = 1; i <= rowIndex; ++i) {
            result.push_back(1);
            for (int j = i - 1; j > 0; --j) {
                result[j] += result[j - 1];
            }
        }

        return result;
    }
};

}  // namespace lc

#endif /* LC_SOLUTION_HPP_ */