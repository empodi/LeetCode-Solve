class Solution:
    def addDigits(self, num: int) -> int:
        
        while num > 9:
            
            digitSum = 0
            
            while num:
                digitSum += num % 10
                num //= 10
                
            num = digitSum
            
        return num
        