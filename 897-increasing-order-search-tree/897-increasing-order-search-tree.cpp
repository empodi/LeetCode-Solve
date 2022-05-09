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
    vector<TreeNode*> v;
    
    TreeNode* increasingBST(TreeNode* root) {
        
        inOrder(root);
        
        int len = v.size();
        
        for (int i = 0; i < len; i++) {
            
            v[i]->right = (i < len - 1) ? v[i + 1] : nullptr;
            v[i]->left = nullptr;
        }
        
        return v[0];
    }
    
    void inOrder(TreeNode* node) {
        
        if (!node) return;
        
        inOrder(node->left);    
        v.push_back(node);
        inOrder(node->right);
    }
};