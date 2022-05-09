class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        if not digits:
            return []
        
        numPad = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        answer = []
        
        digitLen = len(digits)
            
        def solve(letter, idx): # no return
            
            if idx == digitLen:
                answer.append("".join(letter))
                return
            
            alphabets = numPad[int(digits[idx]) - 2]
            
            for alphabet in alphabets:
                letter.append(alphabet)
                solve(letter, idx + 1)
                letter.pop()
                
        solve([], 0)
                
        return answer