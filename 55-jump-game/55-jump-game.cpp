class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if (nums.size() == 1) return true;
        
        int maxIdx = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            
            if (maxIdx < i) return false;
            
            maxIdx = maxIdx > nums[i] + i ? maxIdx : nums[i] + i;
            
            if (maxIdx >= nums.size() - 1) return true;
        }
        
        return false;
    }
    
    /*
    bool canJump(vector<int>& nums) {
        
        if (nums.size() == 1) return true;
        
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        
        for (int i = 1; i < len; i++) {
            if (dp[i - 1] < i) return false;
            
            dp[i] = max(dp[i - 1], nums[i] + i);
            
            if (dp[i] >= len - 1) return true;
        }
        
        if (dp[len - 1] >= len - 1) return true;
        else return false;
    }
    */
};

// [2, 4, 0, 0, 0, 1 ]