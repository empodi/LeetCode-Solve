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
private:
    TreeNode* solve(TreeNode* node) {
        if (!node) return nullptr;
        
        TreeNode* left = solve(node->left);
        TreeNode* right = solve(node->right);
        
        if (left) {
            TreeNode* tmp = left;
            while (tmp->right) tmp = tmp->right;
            tmp->right = node->right;
            node->right = left;
            node->left = nullptr;
        }
        return node;
    }
public:
    void flatten(TreeNode* root) {
        solve(root);
    }
};