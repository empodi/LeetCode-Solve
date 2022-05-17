/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    int targetVal;
    
    TreeNode* solve(TreeNode* original, TreeNode* cloned) {
        
        if (!original) return nullptr;
        
        if (original->val == targetVal) 
            return cloned;
        
        TreeNode* tn = solve(original->left, cloned->left);
        
        if (tn) return tn;
        
        return solve(original->right, cloned->right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if (!original->left && !original->right)
            return cloned;
        
        targetVal = target->val;
        
        return solve(original, cloned);
    }
};