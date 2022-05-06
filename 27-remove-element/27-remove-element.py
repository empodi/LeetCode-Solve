class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        vIdx = 0
        swpIdx = 0
        numsLen = len(nums)
        
        while vIdx < numsLen and nums[vIdx] != val:
            vIdx += 1
            
        swpIdx = vIdx + 1
        
        while swpIdx < numsLen and nums[swpIdx] == val:
            swpIdx += 1
            
        while swpIdx < numsLen:
            
            nums[vIdx], nums[swpIdx] = nums[swpIdx], nums[vIdx]
            
            while vIdx < numsLen and nums[vIdx] != val:
                vIdx += 1
                
            swpIdx = vIdx + 1
        
            while swpIdx < numsLen and nums[swpIdx] == val:
                swpIdx += 1
                
        return vIdx

        