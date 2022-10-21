class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        mins = nums.copy()
        maxs = nums.copy()
        for i in range(1,len(nums)):
            mins[i] = min(mins[i - 1], mins[i])
        for i in range(len(nums) - 2,-1,-1):
            maxs[i] = max(maxs[i + 1], maxs[i])
        for i in range(1,len(nums) - 1):
            if nums[i] > mins[i - 1] and nums[i] < maxs[i + 1]:
                return True
        return False