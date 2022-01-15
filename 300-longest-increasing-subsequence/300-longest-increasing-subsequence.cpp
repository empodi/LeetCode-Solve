class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int len = nums.size();
        int answer = 1, localMax = 1;
        vector<int> dp(len, 1);
        
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                }
            }
            answer = (dp[i] > answer) ? dp[i] : answer;
        }
        
        return answer;
    }
};