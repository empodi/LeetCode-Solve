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
    
    TreeNode* solve(TreeNode* node, TreeNode*& cloned, vector<bool> v) {
        
        if (!node) return nullptr;
        
        if (targetVal == node->val) {
            
            for (bool flag: v) {
                if (flag) cloned = cloned->right;
                else cloned = cloned->left;
            }
            
            return cloned;
        }
        
        TreeNode* tn;
        
        v.push_back(0);
        tn = solve(node->left, cloned, v);
        
        if (tn) return tn;
        
        v.pop_back();
        v.push_back(1);
        
        return solve(node->right, cloned, v);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if (!original->left && !original->right)
            return cloned;
        
        targetVal = target->val;
        vector<bool> v;
        
        return solve(original, cloned, v);
    }
};