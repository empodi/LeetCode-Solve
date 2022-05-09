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
    priority_queue<int> pq;
    int val = 0;
    
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root, k);
        
        return pq.top();
    }
    
    void inorder(TreeNode* root, const int& k) {
        
        if (!root) return;
        
        inorder(root->left, k);
        
        if (pq.size() < k)
            pq.push(root->val);
        
        inorder(root->right, k);
    }
};