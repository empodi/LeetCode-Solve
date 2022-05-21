class Solution {
public:
    int helper(vector<int>& coins, vector<int>& dp, int current) {
        
        if (current < 0) return -1;
        if (current == 0) return 0;
        
        if (dp[current] != 0) return dp[current];
        
        int minVal = INT_MAX;
        
        for (int i = 0; i < coins.size(); i++) {
            
            if (current >= coins[i]) {
                int res = helper(coins, dp, current - coins[i]);
                
                if (res == -1) continue;
                
                if (res + 1 < minVal) minVal = res + 1;
            }
        }
        
        if (minVal == INT_MAX) {
            dp[current] = -1;
        }
        else dp[current] = minVal;
        
        return dp[current];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        if (amount == 0) return 0;
        
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount + 1, 0);
        
        return helper(coins, dp, amount);
    }
};