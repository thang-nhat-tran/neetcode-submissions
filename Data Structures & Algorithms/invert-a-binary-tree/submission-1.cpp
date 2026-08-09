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
    TreeNode* invertTree(TreeNode* root) {
        preorder(root);
        return root;
    }
    void preorder(TreeNode* node) {
        if (node == nullptr) return;
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        swap(node->left, node->right);
        if (left != nullptr) preorder(left);
        if (right != nullptr) preorder(right);
    }
};
