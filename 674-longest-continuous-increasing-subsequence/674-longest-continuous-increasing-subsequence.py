class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        
        localLen = 1
        maxLen = 1
        
        for i, val in enumerate(nums):
            
            if i == 0: continue
                
            if nums[i - 1] < nums[i]:
                localLen += 1
                maxLen = max(maxLen, localLen)
            else:
                localLen = 1
        
        return maxLen
        