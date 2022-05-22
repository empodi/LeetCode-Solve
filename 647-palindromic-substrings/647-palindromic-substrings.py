class Solution:
    def countSubstrings(self, s: str) -> int:
        slen = len(s)
        answer = slen
        dp = [[False for col in range(slen)] for row in range(slen)]
        
        for i in range(slen):
            dp[i][i] = True
            if i > 0:
                dp[i][i - 1] = True
        for gap in range(1, slen):
            for i in range(0, slen - gap):
                if s[i] == s[i + gap] and dp[i + 1][i + gap - 1]:
                    answer += 1
                    dp[i][i + gap] = True
        return answer
        