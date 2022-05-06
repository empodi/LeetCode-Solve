class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        
        if num1 == "0" or num2 == "0":
            return "0"
        
        num1Len, num2Len = len(num1), len(num2)
        
        if num1Len < num2Len:
            num1, num2 = num2, num1
            num1Len, num2Len = num2Len, num1Len
            
        answer = None
        
        def digitMultiply(multiplicand: str, digit: str) -> str:
            mIdx = len(multiplicand) - 1
            carry = 0
            result = ''
            
            while mIdx >= 0 or carry:
                if mIdx >= 0:
                    carry = carry + int(multiplicand[mIdx]) * int(digit)
                result = str(carry % 10) + result
                carry //= 10
                mIdx -= 1
            
            return result
        
        def strSum(a: str, b: str) -> str:
            aIdx, bIdx = len(a) - 1, len(b) - 1
            carry = 0
            result = ''
            
            while aIdx >= 0 or bIdx >= 0 or carry:
                if aIdx >= 0:
                    carry += int(a[aIdx])
                if bIdx >= 0:
                    carry += int(b[bIdx])
                    
                result = str(carry % 10) + result
                carry //= 10
                aIdx -= 1
                bIdx -= 1
            
            return result
        
        for i in range(num2Len - 1, -1, -1):
            
            if num2[i] == "0":
                continue
            
            mul = digitMultiply(num1, num2[i]) + "0" * (num2Len - i - 1)
            
            if not answer:
                answer = mul
            else:
                answer = strSum(answer, mul)

        return answer