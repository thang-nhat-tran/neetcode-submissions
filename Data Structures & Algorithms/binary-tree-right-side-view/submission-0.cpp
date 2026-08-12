/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, int> right_side;
        dfs(root, 0, right_side);
        vector<int> res(right_side.size());
        for (auto& [key, val] : right_side) {
            res[key] = val;
        }
        return res;
    }

    void dfs(TreeNode* node, int depth, unordered_map<int, int>& right_side) {
        if (node == nullptr) return;
        dfs(node->left, depth + 1, right_side);
        dfs(node->right, depth + 1, right_side);
        right_side[depth] = node->val;
    }
};
