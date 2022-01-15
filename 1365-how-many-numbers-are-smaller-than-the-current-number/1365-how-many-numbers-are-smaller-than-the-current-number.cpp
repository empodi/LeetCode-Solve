class Solution {
public:
    int idxArr[101]; // for cross-reference
    
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> temp(nums);
        vector<int> ans(len);
        
        sort(temp.begin(), temp.end());
        memset(idxArr, -1, sizeof(idxArr));
        
        for (int i = 0; i < len; i++) {
            if (idxArr[temp[i]] >= 0) continue;
            idxArr[temp[i]] = i;
        }
        
        for (int i = 0; i < len; i++) {
            ans[i] = idxArr[nums[i]];
        }
        
        return ans;
    }
};