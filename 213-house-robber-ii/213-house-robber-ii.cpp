class Solution {
public:
    int rob(vector<int>& nums) {
        
        int len = nums.size();
        
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(len);
        int max1, max2;
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < len - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        max1 = dp[len - 2];
        
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        
        for (int i = 3; i < len; i++) {
            dp[i] = max(dp[i - 2] + nums[i] , dp[i - 1]);
        }
        max2 = dp[len - 1];
        
        return max(max1, max2);
    }
};