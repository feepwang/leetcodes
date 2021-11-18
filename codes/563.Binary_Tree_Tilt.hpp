/*
 Question:
 * Given the root of a binary tree, return the sum of every tree node's tilt.
 *
 * The tilt of a tree node is the absolute difference between the sum of all
 left
 * subtree node values and all right subtree node values. If a node does not
 have a
 * left child, then the sum of the left subtree node values is treated as 0. The
 * rule is similar if there the node does not have a right child.
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/binary-tree-tilt
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

namespace lc {

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int operator()(TreeNode *root) { return findTilt(root); }

   private:
    int dfs(TreeNode *node) {
        if (nullptr == node) {
            return 0;
        }
        int sum_left = dfs(node->left);
        int sum_right = dfs(node->right);
        ans += abs(sum_left - sum_right);
        return sum_left + sum_right + node->val;
    }

    int findTilt(TreeNode *root) {
        dfs(root);
        return ans;
    }

    int ans = 0;
};

}  // namespace lc

#endif