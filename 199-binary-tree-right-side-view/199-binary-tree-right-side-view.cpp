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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while (cnt) {
            int tmp_cnt = 0;
            while (cnt--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left); 
                    tmp_cnt++;
                }
                if (node->right) {
                    q.push(node->right);
                    tmp_cnt++;
                }
                if (cnt == 0) ans.push_back(node->val);
            }
            cnt = tmp_cnt;
        }
        return ans;
    }
};