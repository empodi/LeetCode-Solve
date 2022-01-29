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
    int cnt = 0;
    
    int helper(TreeNode* node) {
        
        if (!node) return 0;
        
        int leftCost = helper(node->left);
        int rightCost = helper(node->right);
        
        cnt += abs(leftCost) + abs(rightCost);
        
        return node->val + leftCost + rightCost - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        
        helper(root);
        
        return cnt;
    }
};