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
typedef struct __subtreeInfo__ {
    int minVal;
    int maxVal;
    int sum;
    bool flag;
} subtreeInfo;

class Solution {
private:
    int answer = INT_MIN;
    bool isPositive = false;
    
    int threeMin(int x, int y, int z) {
        x = x < y ? x : y;
        return x = x < z ? x : z;
    }
    int threeMax(int x, int y, int z) {
        x = x > y ? x : y;
        return x = x > z ? x : z;
    }
public:
    subtreeInfo solve(TreeNode* node) {

        if (node->val > 0 && !isPositive) 
            isPositive = true;
        
        subtreeInfo cur, lv, rv;
        cur.minVal = cur.maxVal = cur.sum = node->val;
        cur.flag = lv.flag = rv.flag = true;
        lv.maxVal = rv.maxVal = INT_MIN;
        rv.minVal = lv.minVal = INT_MAX;
        
        if (node->left) {
            lv = solve(node->left);
            cur.sum += lv.sum;
            cur.flag = lv.flag && (lv.maxVal < node->val);
        }
        if (node->right) {
            rv = solve(node->right);
            cur.sum += rv.sum;
            cur.flag = cur.flag && rv.flag && (rv.minVal > node->val);
        }
        
        cur.maxVal = threeMax(lv.maxVal, rv.maxVal, cur.maxVal);
        cur.minVal = threeMin(lv.minVal, rv.minVal, cur.minVal);
        
        if (cur.flag) {
            answer = max(cur.sum, answer);
        }
        
        return cur;
    }
    
    int maxSumBST(TreeNode* root) {
        
        solve(root);
        return answer = isPositive ? answer : 0;
    }
};