class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        sLen = len(s)
        answer = s[0:1]
        
        dp = [[False] * sLen for row in range(sLen)]
        
        for i in range(sLen): 
            dp[i][i] = True
            if i > 0:
                dp[i][i - 1] = True
            
        for gap in range(1, sLen):
            for i in range(sLen):
                
                if i + gap < sLen and s[i] == s[i + gap]:
                    if dp[i + 1][i + gap - 1]:
                        dp[i][i + gap] = True
                        answer = s[i:i + gap + 1]

        return answer