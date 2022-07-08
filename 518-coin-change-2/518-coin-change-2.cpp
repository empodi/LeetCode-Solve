class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto& coin : coins){
            for (int i = 1; i <= amount; i++) { // i stands for the current amount
                if (i < coin) continue;
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    } 
};