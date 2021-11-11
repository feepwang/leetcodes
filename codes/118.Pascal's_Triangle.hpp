/*
 * Question
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/pascals-triangle
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef lC_SOLUTION_HPP_
#define lC_SOLUTION_HPP_

// include header
#include <vector>

namespace lc {

class Solution {
   public:
    // overloading operator()
    std::vector<std::vector<int>> operator()(const int& numRows) {
        return generate(numRows);
    }

    // function()
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result{{1}};
        for (int i = 1; i < numRows; ++i) {
            std::vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < i; ++j) {
                tmp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            tmp.push_back(1);
            result.push_back(std::move(tmp));
        }
        return result;
    }
};

}  // namespace lc

#endif