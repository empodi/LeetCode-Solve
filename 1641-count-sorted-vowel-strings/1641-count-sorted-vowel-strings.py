class Solution:
    def countVowelStrings(self, n: int) -> int:
        
        endsWith = [1] * 6;
        endsWith[0] = 0
        
        for i in range(1, n):
            for idx in range(1, 6):
                endsWith[idx] += endsWith[idx - 1]
                
        return sum(endsWith)
                
            
        