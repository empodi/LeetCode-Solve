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
private:
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) { 
        if (ps > pe || is > ie) return nullptr;
        int val = preorder[ps];
        int val_idx = is; // val idx in inorder array
        while (val_idx < inorder.size() && inorder[val_idx] != val) val_idx++;
        TreeNode* node = new TreeNode(val);
        node->left = makeTree(preorder, inorder, ps + 1, ps + val_idx - is, is, val_idx);
        node->right = makeTree(preorder, inorder, ps + val_idx - is + 1, pe, val_idx + 1, ie);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return makeTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};