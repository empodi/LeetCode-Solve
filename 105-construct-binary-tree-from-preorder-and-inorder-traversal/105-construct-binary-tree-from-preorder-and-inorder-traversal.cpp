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
//inline int idx_convert(int a){return a+3000;}
class Solution {
private:
    int inorder_idx[10000] = { 0, };
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) { 
        if (ps > pe || is > ie) return nullptr;
        int val = preorder[ps];
        int val_idx = inorder_idx[val + 3000]; // val idx in inorder array

        TreeNode* node = new TreeNode(val);
        node->left = makeTree(preorder, inorder, ps + 1, ps + val_idx - is, is, val_idx);
        node->right = makeTree(preorder, inorder, ps + val_idx - is + 1, pe, val_idx + 1, ie);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_idx[inorder[i] + 3000] = i;
        }
        return makeTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};