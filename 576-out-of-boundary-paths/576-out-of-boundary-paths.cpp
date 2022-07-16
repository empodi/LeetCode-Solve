#define MOD 1000000007
class Solution {
private:
    int height;
    int width;
    int limit;
    int dp[55][55][55];
    int solve(int i, int j, int mv) {
        if (i < 0 || j < 0 || i >= height || j >= width) return 1;
        if (mv <= 0 || mv > limit) return 0;
        if (dp[i][j][mv] >= 0) return dp[i][j][mv];
        int sum = 0;
        sum += solve(i + 1, j, mv + 1) % MOD; sum %= MOD;
        sum += solve(i - 1, j, mv + 1) % MOD; sum %= MOD;
        sum += solve(i, j - 1, mv + 1) % MOD; sum %= MOD;
        sum += solve(i, j + 1, mv + 1) % MOD; sum %= MOD;
        return dp[i][j][mv] = sum % MOD;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        height = m; width = n; limit = maxMove; 
        memset(dp, -1, sizeof(dp));
        
        return solve(startRow, startColumn, 1);
    }
};