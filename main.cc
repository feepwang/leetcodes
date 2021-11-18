#include <iostream>

//  #include "${SOLUTION_HPP}"
#include "563.Binary_Tree_Tilt.hpp"

int main() {
    using std::cout;
    using std::endl;

    lc::Solution s;

    //std::vector<std::vector<int>> t{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //lc::TreeNode* root =
    //    new lc::TreeNode(1, new lc::TreeNode(2), new lc::TreeNode(3));

    lc::TreeNode left(2), right(3), root(1, &left, &right);

    //  output
    cout << s(&root);

    cout << endl;
}