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
    int findDepth(TreeNode* node) {
        
        if (!node->left && !node->right) return 0;
        
        int ld = node->left ? findDepth(node->left) : 0;
        int rd = node->right ? findDepth(node->right) : 0;
        return 1 + max(ld, rd);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root, int curDepth = 0, int targetDepth = 0) {
        
        if (!targetDepth) 
            targetDepth = findDepth(root);
        if (curDepth == targetDepth || !root) 
            return root;
        
        TreeNode* left = subtreeWithAllDeepest(root->left, curDepth + 1, targetDepth);
        TreeNode* right = subtreeWithAllDeepest(root->right, curDepth + 1, targetDepth);
     
        if (left && right) return root;
        if (left) return left;
        return right;
    }
};