class Solution:
    def addDigits(self, num: int) -> int:
        
        if not num:
            return 0
        
        mod = num % 9
        
        return mod if mod else 9
        
        
"""
def addDigits(self, num: int) -> int:
        
    while num > 9:
            
        digitSum = 0
            
        while num:
            digitSum += num % 10
            num //= 10
                
        num = digitSum
            
    return num
"""