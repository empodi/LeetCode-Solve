class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        check = [-1 for x in range(26)]
        answer = float("inf")
        
        for i, c in enumerate(s):
            
            cIdx = ord(c) - ord("a")
            
            if check[cIdx] == -1:
                check[cIdx] = i
            elif check[cIdx] >= 0:
                check[cIdx] = -2
                
        found = False
        
        for i in range(26):
            
            if check[i] < 0: 
                continue
            
            found = True
            answer = min(answer, check[i])
                
        return answer if found else -1
            
            
            
        