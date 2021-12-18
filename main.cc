#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "419.Battleships_in_a_Board.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;
    std::vector<std::vector<char>> board{
        {'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};

    //  output
    cout << s(board);
    cout << endl;
}