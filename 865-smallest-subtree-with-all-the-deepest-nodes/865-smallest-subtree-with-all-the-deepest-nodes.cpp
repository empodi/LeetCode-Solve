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
    
    TreeNode* getSubtree(TreeNode* node, int curDepth, const int& targetDepth) {
        
        if (curDepth == targetDepth || !node) return node;
        
        TreeNode* left = getSubtree(node->left, curDepth + 1, targetDepth);
        TreeNode* right = getSubtree(node->right, curDepth + 1, targetDepth);
        
        if (left && right) return node;
        if (left) return left;
        return right;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
     
        if (!root->left && !root->right) return root;
        return getSubtree(root, 0, findDepth(root));
    }
};