class Solution:
    def validPalindrome(self, s: str) -> bool:
        
        def check(left, right) -> bool:
            
            while left < right:
                if s[left] != s[right]:
                    return False;
                left, right = left + 1, right - 1
        
            return True
        
        
        flag = False
        left, right = 0, len(s) - 1
        
        while left < right:
            
            if s[left] == s[right]:
                left, right = left + 1, right - 1
                continue
            
            if s[left] != s[right]:
                if check(left + 1, right) or check(left, right - 1):
                    return True
                else:
                    return False
        
        return True
            