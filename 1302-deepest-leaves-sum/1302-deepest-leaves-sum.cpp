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
    int deepestLeavesSum(TreeNode* root) {
            
        queue<TreeNode*> q;
        q.push(root);
        
        int levelCnt = 1;
        int answer = 0;
        
        while (levelCnt) {
            
            int cnt = 0;
            answer = 0;
            
            for (int i = 0; i < levelCnt; i++) {
                
                TreeNode* node = q.front();
                q.pop();
                
                answer += node->val;
                
                if (node->left) {
                    q.push(node->left);
                    cnt++;
                }
                if (node->right) {
                    q.push(node->right);
                    cnt++;
                }
            }
            
            levelCnt = cnt;
        }
        
        return answer;
    }
};