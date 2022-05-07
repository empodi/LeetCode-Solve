class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        
        sLen = len(s)
        
        for i in range(sLen // 2):
            s[i], s[sLen - 1 - i] = s[sLen - 1 - i], s[i]
            
        