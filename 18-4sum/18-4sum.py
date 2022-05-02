class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        numsLen = len(nums)
        
        if numsLen < 4: return []
        
        nums.sort()
        answer = []
        
        i = 0
        while i < numsLen - 3:
            
            if nums[i] > 0 and nums[i] > target:
                i += 1
                continue
                
            j = i + 1
            while j < numsLen - 2:
                
                twoSum = nums[i] + nums[j]
                
                if twoSum > 0 and twoSum > target: 
                    j += 1
                    continue
                
                left = j + 1
                right = numsLen - 1
                
                while left < right:
                    totalSum = twoSum + nums[left] + nums[right]
                    
                    if totalSum == target:
                        answer.append([nums[i], nums[j], nums[left], nums[right]])
                        
                        left += 1
                        while left < right and nums[left] == nums[left - 1]: 
                            left += 1
                            
                        right -= 1
                        while left < right and nums[right] == nums[right + 1]:
                            right -= 1
                    elif totalSum > target:
                        right -= 1
                    else: 
                        left += 1
                        
                j += 1
                while j < numsLen - 2 and nums[j] == nums[j - 1]:
                    j += 1

            i += 1
            while i > 0 and i < numsLen - 3 and nums[i] == nums[i - 1]: 
                i += 1
                            
        return answer
                    
        
        
        