class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));
        for (int i = 1; i <= coins.size(); i++)
            dp[0][i] = 1;
        for (int i = 1; i <= amount; i++) { // i stands for current amount
            for (int j = 1; j <= coins.size(); j++) {   // first j coins are used
                dp[i][j] = dp[i][j - 1] + (coins[j - 1] > i ? 0 : dp[i - coins[j - 1]][j]); 
            }
        }
        return dp[amount][coins.size()];
    }
};