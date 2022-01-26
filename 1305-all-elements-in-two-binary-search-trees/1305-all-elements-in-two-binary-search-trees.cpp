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
    vector<int> ret;
    
    void makeArray(TreeNode* node, int treeNum) {
        
        if(!node) return;
        makeArray(node->left, treeNum);
        
        if (treeNum == 1) ret.push_back(node->val);
        else {
            auto it = lower_bound(ret.begin(), ret.end(), node->val);
            ret.insert(it, node->val);
        }
        
        makeArray(node->right, treeNum);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        makeArray(root1, 1);
        makeArray(root2, 2);
        
        return ret;
    }
};