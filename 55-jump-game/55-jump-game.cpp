class Solution {
public:
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
        
        return true;
    }
};

// [2, 4, 0, 0, 0, 1 ]