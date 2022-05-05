class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        
        numsLen = len(nums)
        
        posIdx, negIdx = 0, 1
        
        answer = [0 for x in range(numsLen)]
        
        for i, num in enumerate(nums):
            
            if num > 0:
                answer[posIdx] = num
                posIdx += 2
            else:
                answer[negIdx] = num
                negIdx += 2
                
        return answer
        
        
        
        
        
        