class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t): 
            return False
        
        alpha = [0] * 128
        
        for c in s:
            alpha[ord(c)] += 1
        
        for c in t:
            if alpha[ord(c)] == 0:
                return False
            else:
                alpha[ord(c)] -= 1
        
        return True