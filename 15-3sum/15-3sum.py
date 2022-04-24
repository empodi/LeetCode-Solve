class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        numLen = len(nums)
        ret = []
        
        if numLen < 3: return ret
        
        nums.sort()
        
        i = 0
        while i < numLen - 2:
            
            j, k = i + 1, numLen - 1
            
            while j < k:
                s = nums[j] + nums[k] + nums[i]
                
                if s == 0:
                    ret.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while k > 0 and nums[k] == nums[k + 1]: k -= 1
                    while j < numLen and nums[j] == nums[j - 1]: j += 1
                elif s > 0:
                    k -= 1
                    while k > 0 and nums[k] == nums[k + 1]: k -= 1
                else:
                    j += 1
                    while j < numLen and nums[j] == nums[j - 1]: j += 1

            i += 1
            while i < numLen and nums[i] == nums[i - 1]: i += 1
                    
        return ret
            
            
        
        
        