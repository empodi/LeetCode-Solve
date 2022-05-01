class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        colors = [0,0,0]
        
        for num in nums:
            colors[num] += 1
            
        #print(colors)
        idx = 0
        rwb = 0
        
        for color in colors:
            for i in range(idx, idx + color):
                nums[i] = rwb
            idx += color
            rwb += 1
            
        