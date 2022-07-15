inline int MAX(int a, int b) { return a>b ? a:b; }
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int answer = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = MAX(dp[i - 1] + nums[i], nums[i]);
            answer = MAX(answer, dp[i]);
        }
        return answer;
    }
};