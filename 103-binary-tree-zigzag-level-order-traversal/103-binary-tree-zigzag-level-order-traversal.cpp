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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ret;
        bool flag = false; // forward or backward
        int cnt = 1; 
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        while (cnt) {
            int tmp_cnt = 0;
            ret.push_back({});
            for (int i = 0; i < cnt; i++) {
                if (flag) { 
                    if (dq.back()->right) {
                        dq.push_front(dq.back()->right);
                        tmp_cnt++;
                    }
                    if (dq.back()->left) {
                        dq.push_front(dq.back()->left);
                        tmp_cnt++;
                    }
                    ret.back().push_back(dq.back()->val);
                    dq.pop_back();
                }
                else {  
                    if (dq.front()->left) {
                        dq.push_back(dq.front()->left);
                        tmp_cnt++;
                    }
                    if (dq.front()->right) {
                        dq.push_back(dq.front()->right);
                        tmp_cnt++;
                    }
                    ret.back().push_back(dq.front()->val);
                    dq.pop_front();
                }
            }
            cnt = tmp_cnt;
            flag = !flag;
        }
        return ret;
    }
};