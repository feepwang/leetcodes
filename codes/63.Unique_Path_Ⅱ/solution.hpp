/*
 * Question
 */

#ifndef SOLU_SOL_HPP_
#define SOLU_SOL_HPP_

// include header
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
   public:
    // overloading operator()
    int operator()(vector<vector<int>>& obstacleGrid) {
        return uniquePathsWithObstacles(obstacleGrid);
    }

    // function()
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto row = obstacleGrid.size(), col = obstacleGrid.at(1).size();

        vector<vector<int>> trace(row, vector<int>(col));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    trace[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    trace[i][j] = 1;
                } else if (i == 0) {
                    trace[i][j] = trace[i][j - 1];
                } else if (j == 0) {
                    trace[i][j] = trace[i - 1][j];
                } else {
                    trace[i][j] = trace[i][j - 1] + trace[i - 1][j];
                }
            }
        }
        return trace[row - 1][col - 1];
    }
};

#endif