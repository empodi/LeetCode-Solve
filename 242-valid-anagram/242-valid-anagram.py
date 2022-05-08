class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        sArray = [0] * 26;
        tArray = [0] * 26;
        
        for c in s:
            sArray[ord(c) - 97] += 1
            
        for c in t:
            tArray[ord(c) - 97] += 1
            
        ret = True
            
        for i in range(26):
            if sArray[i] != tArray[i]:
                ret = False
                break
            
        return ret
        