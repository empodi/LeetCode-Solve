class Solution {
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0,1);
        int slen = s.length();
        bool dp[1001][1001];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < slen; i++) {
            dp[i][i] = true;
            if (i) dp[i][i - 1] = true;
        }
        
        for (int len = 2; len <= slen; len++) {
            for (int i = 0; i <= slen - len; i++) {
                if (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2]) {
                    dp[i][i + len - 1] = true;
                    if (ans.length() < len) {
                        ans = s.substr(i, len);
                        cout << ans;
                    }
                }
            }
        }
        
        return ans;
    }
};