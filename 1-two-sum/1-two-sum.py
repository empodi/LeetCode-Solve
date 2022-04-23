class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        hashTable = dict()
        
        for i, val in enumerate(nums):
            
            pairVal = target - val
            
            if pairVal in hashTable:
                return [hashTable[pairVal], i]
            else:
                hashTable[val] = i
            
                