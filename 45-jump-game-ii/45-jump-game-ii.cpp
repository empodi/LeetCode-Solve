class Solution {
public:
    int jump(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> dp(len, 0); 
        // store the number of minimum jumps to reach ith index
        
        for (int i = 0; i < len; i++) {
            int curMax = min(len - 1, i + nums[i]);
            int jump = dp[i] + 1;
            
            for (int j = i + 1; j <= curMax; j++) {
                if (dp[j]) continue;
                dp[j] = jump;
                if(j == len - 1) break;
            }
        }
        
        return dp[len - 1];
    }
};