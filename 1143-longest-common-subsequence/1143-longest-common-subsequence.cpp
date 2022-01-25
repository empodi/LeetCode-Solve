class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        
        int aLen = a.length();
        int bLen = b.length();
        
        vector<vector<int>> dp(aLen + 1, vector<int>(bLen + 1, 0));
        
        for (int i = 0; i < aLen; i++) {
            for (int j = 0; j < bLen; j++) {
                
                if (a[i] == b[j]) 
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[aLen][bLen];
    }
};