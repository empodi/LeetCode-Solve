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
    int depth[501];
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root, int curDepth = 0) {
        
        if (!root) 
            return nullptr;
        
        depth[root->val] = curDepth;
        
        if (!root->left && !root->right) 
            return root;
        
        TreeNode *left = subtreeWithAllDeepest(root->left, curDepth + 1);
        TreeNode* right = subtreeWithAllDeepest(root->right, curDepth + 1);
        
        int lv = left ? depth[root->left->val] : 0;
        int rv = right ? depth[root->right->val] : 0;
        
        depth[root->val] = lv > rv ? lv : rv;
        
        if (left && right){
            if (lv == rv) return root;
            else if (lv > rv) return left;
            else return right;
        }
        if (left) return left;
        return right;
    }
};