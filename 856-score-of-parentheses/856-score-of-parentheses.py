class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        
        sLen = len(s)
        
        totalScore = 0
        
        stack = []
        
        for i in range(sLen):
            
            if s[i] == "(":
                stack.append(-1)  
            else:
                if stack[-1] == -1:
                    stack.pop()
                    stack.append(1)
                else:
                    score = 0
                    
                    while stack and stack[-1] != -1:
                        score += stack[-1]
                        stack.pop()
                    
                    stack.pop()
                    stack.append(score * 2)

        while stack:
            totalScore += stack[-1]
            stack.pop()
            
        return totalScore
            
            