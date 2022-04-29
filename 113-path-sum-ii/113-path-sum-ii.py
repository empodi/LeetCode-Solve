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
    vector<vector<int>> ans;
    
    void DFS(TreeNode* node, vector<int>& v, int curSum, int& targetSum) {
        
        if (!node) return;
        
        curSum += node->val;
        v.push_back(node->val);
            
        if (!node->left && !node->right) {
            if (curSum == targetSum) {
                ans.push_back(v);
            }
        }
        
        DFS(node->left, v, curSum, targetSum);
        DFS(node->right, v, curSum, targetSum);
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> v;
        DFS(root, v, 0, targetSum);
        
        return ans;
    }
};