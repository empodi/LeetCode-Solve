class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        ret = [0, 0]
        listLen = len(nums)
        
        for i in range(0, listLen):
            for j in range(i + 1, listLen):
                if (nums[i] + nums[j] == target):
                    ret[0] = i
                    ret[1] = j
                    
        return ret
                