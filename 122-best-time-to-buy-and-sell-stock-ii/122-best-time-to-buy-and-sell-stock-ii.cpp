class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(),0);
        int curmin = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = max(dp[i - 1], max(prices[i] - curmin, prices[i] - prices[i - 1] + dp[i - 1]));
            curmin = min(curmin, prices[i]);
        }
        return dp.back();
    }
};