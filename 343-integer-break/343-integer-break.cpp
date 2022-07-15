inline int MAX(int a,int b) {return a>b ? a:b;}
class Solution {
public:
    int integerBreak(int n) {
        int dp[60] = { 0, };
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = MAX(dp[i], j * MAX( (i - j) , (dp[i - j]) ));
            }
        }
        return dp[n];
    }
};