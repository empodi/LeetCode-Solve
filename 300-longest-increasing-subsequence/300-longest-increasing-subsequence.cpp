inline int MAX(int a,int b){return a>b?a:b;}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int answer = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) 
                    dp[i] = MAX(dp[i], dp[j] + 1);
            }
            answer = MAX(answer, dp[i]);
        }
        return answer;
    }
};