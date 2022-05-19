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
        
        depth[root->val] = curDepth;
        
        TreeNode *left = nullptr, *right = nullptr;
        int lv = 0, rv = 0;
        
        if (root->left) {
            left = subtreeWithAllDeepest(root->left, curDepth + 1);
            lv = depth[root->left->val];
        }
        if (root->right) {
            right = subtreeWithAllDeepest(root->right, curDepth + 1);
            rv = depth[root->right->val];
        }
        
        if (!left && !right) return root;

        depth[root->val] = max(lv, rv);
        
        if (left && right){
            if (lv == rv) return root;
            else if (lv > rv) return left;
            else return right;
        }
        if (left) return left;
        return right;
    }
};