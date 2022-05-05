class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        
        totalScore = 0
        stack = []
        
        for c in s:
            
            if c == "(":
                stack.append(-1)  
            else:
                score = 0
                    
                while stack and stack[-1] != -1:
                    score += stack[-1]
                    stack.pop()
                    
                stack.pop()
                
                if score == 0:
                    stack.append(1)
                else:
                    stack.append(score * 2)
            
        return sum(stack)
            
            