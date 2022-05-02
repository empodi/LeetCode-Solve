class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        numsLen = len(nums)
        
        def binarySearch() -> int:
            
            left = 0
            right = numsLen - 1
            
            while left <= right:
                
                mid = int((left + right) / 2)
                if nums[mid] == target: return mid
                if (nums[mid] < target): left = mid + 1
                else: right = mid - 1
            
            return -1
        
        idx = binarySearch()
        
        if idx < 0: return [-1,-1]
        
        start = idx
        end = idx
        
        while start > 0 and nums[start] == target:
            start -= 1
        
        if start > 0 or nums[start] != target: start += 1
            
        while end < numsLen and nums[end] == target:
            end += 1
        
        end -= 1
            
        return [start, end]
            
            