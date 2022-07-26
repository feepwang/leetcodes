/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    bool operator()(vector<vector<int>>& matrix, const int& target) {
        return searchMatrix(matrix, target);
    }

    // function()
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t rup = 0, rdown = matrix.size(), rpivot = rdown / 2;
        size_t cleft = 1, cright = matrix[0].size(), cpivot = cright / 2;

        while (rup < rdown) {
            if (matrix[rpivot][0] == target) {
                return true;
            } else if (matrix[rpivot][0] > target) {
                rdown = rpivot;
            } else {
                rup = rpivot + 1;
            }
            rpivot = rup + (rdown - rup) / 2;
        }
        rpivot = rpivot ? rpivot - 1 : 0;

        while (cleft < cright) {
            if (matrix[rpivot][cpivot] == target) {
                return true;
            } else if (matrix[rpivot][cpivot] > target) {
                cright = cpivot;
            } else {
                cleft = cpivot + 1;
            }
            cpivot = cleft + (cright - cleft) / 2;
        }

        return false;
    }
};

#endif