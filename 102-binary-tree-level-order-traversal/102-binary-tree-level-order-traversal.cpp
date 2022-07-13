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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while (cnt) {
            int tmp_cnt = 0;
            ret.push_back({});
            while (cnt--) {
                ret.back().push_back(q.front()->val);
                if (q.front()->left) {
                    tmp_cnt++;
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    tmp_cnt++;
                    q.push(q.front()->right);
                }
                q.pop();
            }
            cnt = tmp_cnt;
        }
        return ret;
    }
};