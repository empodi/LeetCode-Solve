class Solution {
public:
    int rob(vector<int>& nums) {
       
        int len = nums.size();
        
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        
        vector<vector<int>> dp(2, vector<int>(len, 0));
        
        dp[0][0] = dp[1][0] = nums[0];
        dp[0][1] = nums[1];
        dp[1][1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < len; i++) {
            dp[0][i] += max(dp[0][i - 2], dp[1][i - 2]) + nums[i];
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]); 
        }
        
        return max(dp[0][len - 1], dp[1][len - 1]);
    }
};