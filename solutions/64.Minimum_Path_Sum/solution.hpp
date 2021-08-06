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
    int operator()(vector<vector<int>>& grid) { return minPathSum(grid); }

    // function()
    int minPathSum(vector<vector<int>>& grid) {
        auto row = grid.size(), col = grid[0].size();
        vector<vector<int>> trace(row, vector<int>(col));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) {
                    trace[i][j] = grid[i][j];
                } else if (i == 0) {
                    trace[i][j] = trace[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    trace[i][j] = trace[i - 1][j] + grid[i][j];
                } else {
                    trace[i][j] =
                        (trace[i - 1][j] < trace[i][j - 1] ? trace[i - 1][j]
                                                           : trace[i][j - 1]) +
                        grid[i][j];
                }
            }
        }

        return trace[row - 1][col - 1];
    }
};

#endif