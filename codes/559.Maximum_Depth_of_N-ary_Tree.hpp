/*
 * Question:
 * Given a n-ary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root
 * node down to the farthest leaf node.
 *
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#ifndef LC_SOLUTION_HPP_
#define LC_SOLUTION_HPP_

#include <queue>
#include <vector>

namespace lc {

// Definition for a Node.
class Node {
   public:
    int val{};
    std::vector<Node*> children{};

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    int operator()(Node* root) { return maxDepth(root); }

   private:
    //  DFS with O(n) in time and O(1) in memory
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        std::vector<Node*> children = root->children;
        for (auto child : children) {
            int child_depth = maxDepth(child);
            depth = std::max(child_depth, depth);
        }
        return depth + 1;
    }

    //  BFS with O(n) in time and O(n) in memory
    // int maxDepth(Node* root) {
    //    if (nullptr == root) {
    //        return 0;
    //    }
    //    std::queue<Node*> q({root});
    //    int depth{0}, level_size{1};
    //    auto cur = nullptr;
    //    while (!q.empty()) {
    //        ++depth;
    //        int next_level{0};
    //        while (level_size) {
    //            next_level += q.front()->children.size();
    //            for (auto node : q.front()->children) {
    //                q.push(node);
    //            }
    //            q.pop();
    //            --level_size;
    //        }
    //        level_size = next_level;
    //    }

    //    return depth;
    //}
};

}  // namespace lc

#endif