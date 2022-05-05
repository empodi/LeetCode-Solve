class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        # make b longer
        if len(a) > len(b):
            a, b = b, a
            
        aIdx = len(a) - 1
        bIdx = len(b) - 1
        array = []
        
        carry = 0
        
        while bIdx >= 0:
            
            aBin = int(a[aIdx]) if aIdx >= 0 else 0
                
            val = carry + aBin + int(b[bIdx])
                
            array.append(str(val % 2))
            carry = int(val / 2)
            
            aIdx -= 1
            bIdx -= 1
        
        if carry:
            array.append("1")
        
        return "".join(array)[::-1]