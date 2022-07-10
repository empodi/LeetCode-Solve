inline int bi_max(int a, int b) { return a>b ? a:b; }
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int answer = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = bi_max(dp[i - 1] + nums[i], nums[i]);
            answer = bi_max(answer, dp[i]);
        }
        return answer;
    }
};