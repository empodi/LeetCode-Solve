class Solution:
    def removeDuplicates(self, s: str) -> str:
        
        idx = 0
        
        while True:
            
            isDup = False
            sLen = len(s)
            
            while idx < sLen - 1:
                
                if s[idx] == s[idx + 1]:
                    
                    isDup = True
                    s = s[:idx] + s[idx + 2:]
                    idx = 0 if idx == 0 else idx - 1
                    break
                else:
                    idx += 1
            
            if isDup == False:
                break
                
        return s