class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        string ret;
        int maxLen = 0, start = 0, end = 0;
        
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        
        for (int i = 0; i < len; i++)
            dp[i][i] = true;
        
        for (int d = 1; d < len; d++) {
            for (int j = 0; j < len - d; j++){
                
                if (s[j] == s[j + d]) {
                    
                    if (d == 1 || dp[j + 1][j + d - 1]) {
                        
                        dp[j][j + d] = true;
                        
                        if (d + 1 > maxLen) {
                            maxLen = d + 1;
                            start = j;
                            end = j + d;
                        } 
                    }   
                }
            }
        }

        for (int i = start; i <= end ; i++)
            ret.push_back(s[i]);
        
        return ret;
    }
};