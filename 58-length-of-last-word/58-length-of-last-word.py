class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        
        strings = s.split(" ")
        
        return len(strings[len(strings) - 1])
        
        