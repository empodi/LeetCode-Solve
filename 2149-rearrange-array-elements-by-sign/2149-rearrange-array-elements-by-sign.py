class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        
        numsLen = len(nums)
        
        pos = []
        neg = []
        answer = [0 for i in range(numsLen)]
        
        for num in nums:
            
            if num > 0:
                pos.append(num)
            else:
                neg.append(num)
                
        
        for i in range(int(numsLen / 2)):
            
            answer[i * 2] = pos[i]
            answer[i * 2 + 1] = neg[i]
        
        return answer
        
        
        
        
        