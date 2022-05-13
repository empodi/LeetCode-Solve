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
    int solve(TreeNode* root) {
        
        if (!root) return 0;
        
        if (!root->left && !root->right) return 1;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if (left == -1 || right == -1) return -1;
        
        if (abs(left - right)  > 1) return -1;
        
        return max(solve(root->left), solve(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        
        
        return solve(root) != -1;
    }
};