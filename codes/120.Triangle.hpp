/*
 * Qustion:
 * Given a triangle array, return the minimum path sum from top to bottom.
 *
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 *
 * ��Դ�����ۣ�LeetCode��
 * ���ӣ�https://leetcode-cn.com/problems/triangle
 * ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <algorithm>
#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<std::vector<int>>& triangle) {
        return minimumTotal(triangle);
    }

   private:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        for (size_t r_sz = triangle.size(), i = r_sz - 1; i > 0; --i) {
            for (size_t c_sz = triangle[i - 1].size(), j = 0; j < c_sz; ++j) {
                triangle[i - 1][j] +=
                    std::min(triangle[i][j], triangle[i][j + 1]);
            }
        }

        return triangle[0][0];
    }
};

}  // namespace lc

#endif