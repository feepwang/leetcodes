/*
 * Question:
 * Given an m x n matrix board where each cell is a battleship 'X' or empty '.',
 * return the number of the battleships on board.
 *
 * Battleships can only be placed horizontally or vertically on board. In other
 * words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1
 * (k rows, 1 column), where k can be of any size. At least one horizontal or
 * vertical cell separates between two battleships (i.e., there are no adjacent
 * battleships).
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/battleships-in-a-board
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <vector>

namespace lc {

class Solution {
   public:
    int operator()(std::vector<std::vector<char>>& board) {
        return countBattleships(board);
    }

   private:
    int countBattleships(std::vector<std::vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int result = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    if (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }
                    result++;
                }
            }
        }
        return result;
    }
};

}  // namespace lc

#endif