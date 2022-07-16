inline int MAX(int a, int b) {return a>b ? a:b;}
class Solution {
private:
    int dp[1001][1001] = { 0, };
public:
    int longestPalindromeSubseq(string s) {
        int sLen = s.length();
        
        for (int len = 0; len < sLen; len++) {
            for (int i = 0; i + len <= sLen; i++) {
                if (len == 0) 
                    dp[i][i + len] = 1;
                else if (s[i] == s[i + len]) 
                    dp[i][i + len] = dp[i + 1][i + len - 1] + 2;
                else 
                    dp[i][i + len] = MAX(dp[i][i + len - 1], dp[i + 1][i + len]);
            }
        }
        /*
        for (int i = 0; i < sLen; i++) {
            for (int j = 0; j < sLen; j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        */
        return dp[0][sLen - 1];
    }
};