class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        alphabet = [0] * 26;
        
        for c in s:
            alphabet[ord(c) - 97] += 1
        
        for c in t:
            alphabet[ord(c) - 97] -= 1
            
            if alphabet[ord(c) - 97] < 0:
                return False
            
        return True
        