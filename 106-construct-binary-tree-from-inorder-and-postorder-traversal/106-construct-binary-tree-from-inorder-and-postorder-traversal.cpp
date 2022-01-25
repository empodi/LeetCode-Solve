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
    TreeNode* helper(vector<int>& in, int inS, int inE, vector<int>& po, int poS, int poE) {
        if (inS > inE || poS > poE) return nullptr;
        
        TreeNode* node = new TreeNode(po[poE]);
        
        int center = inS;
        while(in[center] != po[poE]) center++;
        
        node->left = helper(in, inS, center - 1, po, poS, poS + center - inS - 1);
        node->right = helper(in, center + 1, inE, po, poS + center - inS, poE - 1);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        
    }
};