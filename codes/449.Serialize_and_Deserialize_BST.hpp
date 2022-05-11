/*
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 *
 * 设计一个算法来序列化和反序列化 二叉搜索树 。
 * 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 *
 * 编码的字符串应尽可能紧凑。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
#include <vector>

namespace lc {

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
   public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::vector<int> nodes{};
        std::string result;

        seHelper(nodes, root);

        for (auto i : nodes) {
            result += std::to_string(i) + '#';
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data.empty()) {
            return nullptr;
        }

        std::vector<int> nodes{};
        std::string tmp{};
        for (auto c : data) {
            if (c == '#') {
                nodes.push_back(std::stoi(tmp));
                tmp = "";
            } else {
                tmp += c;
            }
        }

        return deHelper(nodes, 0, nodes.size() - 1);
    }

   private:
    void seHelper(std::vector<int>& nodes, TreeNode* root) {
        if (root == nullptr) return;
        nodes.push_back(root->val);
        seHelper(nodes, root->left);
        seHelper(nodes, root->right);
    }

    TreeNode* deHelper(std::vector<int>& nodes, int l, int r) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(nodes[l]);

        int bound = r + 1;
        for (int i = l + 1; i <= r; i++) {
            if (nodes[i] > nodes[i]) continue;
            bound = i;
            break;
        }

        root->left = deHelper(nodes, l + 1, bound - 1);
        root->right = deHelper(nodes, bound, r);

        return root;
    }
};

}  // namespace lc

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;