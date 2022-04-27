class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        
        if len(nums) < 2: return []
        
        arr = [0 for i in range(100001)]
        ans = []
        
        for n in nums:
            arr[n] += 1
        
        for i in range(100001):
            if arr[i] == 2:
                ans.append(i)
        
        return ans