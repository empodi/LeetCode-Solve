class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        if not nums: 
            return 0
        
        def mySort(a, b):
            if a == val:
                return 1
            if b == val:
                return -1
            return 0
        
        nums.sort(key=cmp_to_key(mySort))
        
        idx = 0
        
        while idx < len(nums) and nums[idx] != val:
            idx += 1
            
        return idx
        
        
        
        
                

        