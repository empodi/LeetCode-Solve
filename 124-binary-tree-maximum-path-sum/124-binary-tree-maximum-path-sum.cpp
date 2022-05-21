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
#define MIN -40000000
typedef struct _pathInfo_ {
    int leftPath;
    int rightPath;
} pathInfo;

class Solution {
private:
    int answer;
    int getMax(int a, int b, int c, int d, int e) {
        a = a > b ? a : b;
        a = a > c ? a : c;
        a = a > d ? a : d;
        return a > e ? a : e;
    }
    
    pathInfo solve(TreeNode* node) {
        
        pathInfo cur;
        cur.leftPath = cur.rightPath = MIN;
        int lp=MIN, rp=MIN, tp=MIN;
        
        if (!node) return cur;
        
        //if (!node->left && !node->right) 
            //cur.leftPath = cur.rightPath = node->val;
        if (node->left) {
            pathInfo lv = solve(node->left);
            lp = max(lv.leftPath, lv.rightPath);
        }
        if (node->right) {
            pathInfo rv = solve(node->right);
            rp = max(rv.leftPath, rv.rightPath);
        }
        
        cur.leftPath = max(node->val, node->val + lp);
        cur.rightPath = max(node->val, node->val + rp);
        answer = getMax(answer, node->val, cur.leftPath, cur.rightPath, node->val + lp + rp);

        return cur;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        solve(root);
        return answer;
    }
};