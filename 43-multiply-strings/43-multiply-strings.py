class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        
        if num1 == "0" or num2 == "0":
            return "0"
        
        if len(num1) < len(num2):
            num1, num2 = num2, num1
            
        num1Len, num2Len = len(num1), len(num2)
        answer = None
        
        def digitMultiply(multiplicand: str, digit: str):
            carry = 0
            result = ''
            
            for m in reversed(multiplicand):
                carry = carry + int(m) * int(digit)
                result += str(carry % 10)
                carry //= 10
            
            if carry:
                result += str(carry)
            
            return result[::-1]
        
        def strSum(a, b):
            a, b = list(a), list(b)
            carry = 0
            result = ''
            
            while a or b or carry:
                if a:
                    carry += int(a.pop())
                if b:
                    carry += int(b.pop())
                result += str(carry % 10)
                carry //= 10
            
            return result[::-1]
        
        for i in range(num2Len - 1, -1, -1):
            
            if num2[i] == "0":
                continue
            
            mul = digitMultiply(num1, num2[i]) + "0" * (num2Len - i - 1)
            print(mul)
            
            if not answer:
                answer = mul
            else:
                answer = strSum(answer, mul)

        return answer