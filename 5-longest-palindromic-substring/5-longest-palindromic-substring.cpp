class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1001][1001];
        int sLen = s.size();
        string ans = s.substr(0,1); 
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < sLen; i++) {
            dp[i][i] = true;
            if (i) dp[i][i - 1] = true;
        }
        
        for (int len = 2; len <= sLen; len++) {
            for (int i = 0; i <= sLen - len; i++) {
                if (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2]) {
                    if (ans.size() < len) {
                        ans = s.substr(i, len);
                    }
                    dp[i][i + len - 1] = true;
                }
            }
        }
        
        return ans;
    }
};