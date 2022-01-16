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
    int ret = 0;
    
    int helper(TreeNode* node) {
        
        if (node == NULL) return 0;
        
        int left = helper(node->left);
        int right = helper(node->right);
        
        if (left + right > ret) ret = left + right;
        
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (!root->left && !root->right) return 0;
        
        helper(root);
        
        return ret;
    }
};