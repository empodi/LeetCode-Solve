class Solution:
    def removeDuplicates(self, letters: str, k: int) -> str:
        
        stack = []
        
        for letter in letters:
            
            if not stack or stack[-1][0] != letter:
                stack.append([letter, 1])
            else:
                if stack[-1][1] == k - 1:
                    stack.pop()
                else:
                    stack[-1][1] += 1
                
        return "".join(st[0] * st[1] for st in stack)
            
        
        
        