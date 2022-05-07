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
    int len;
    vector<pair<int, int>> sortedNums;
    
    void setSortedNums(vector<int>& nums) {
        
        for (int i = 0; i < len; i++) {
            sortedNums.push_back({nums[i], i});
        }
        
        sort(sortedNums.begin(), sortedNums.end());   
    }
    
    int findIdx(int left, int right) {
        
        int idx = len - 1;
        
        while (idx >= 0) {
            int sIdx = sortedNums[idx].second;
            
            if (sIdx >= left && sIdx <= right) {
                sortedNums[idx].second = -1;
                return sIdx;
            }
            idx--;
        }
        return -1;
    }
    
    TreeNode* getChild(vector<int>& nums, int left, int right) {
        
        int idx = findIdx(left, right); // get the idx of num for node in nums
        
        if (idx < 0) return nullptr;
        
        TreeNode* node = new TreeNode(nums[idx]);
        
        node->left = getChild(nums, left, idx - 1);
        node->right = getChild(nums, idx + 1, right);
        
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        len = nums.size();
        
        setSortedNums(nums);
        
        return getChild(nums, 0, len - 1);
    }
};