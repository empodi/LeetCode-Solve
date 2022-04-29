class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        dest = len(nums)
        pos = 0
        
        for i in range(0, dest):
            
            pos = max(i + nums[i], pos)
            
            if pos >= dest - 1: return True
            if pos <= i: return False
                
        return True