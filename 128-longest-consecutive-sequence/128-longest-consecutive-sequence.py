class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        nums.sort()
        
        maxLen = 0
        numLen = len(nums)
        idx = 0
        
        while idx < numLen:
            
            localLen = 1
            
            while idx + 1 < numLen:
                
                if nums[idx] == nums[idx + 1]:
                    idx += 1
                    continue
                elif nums[idx] + 1 == nums[idx + 1]:
                    localLen += 1
                else: break
                    
                idx = idx + 1
                
            maxLen = max(maxLen, localLen)
            idx += 1
            
        return maxLen
        
            