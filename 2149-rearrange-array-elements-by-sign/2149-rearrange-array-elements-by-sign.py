class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        
        numsLen = len(nums)
        
        pos = []
        neg = []
        answer = []
        
        for num in nums:
            
            if num > 0:
                pos.append(num)
            else:
                neg.append(num)
                
        
        for i in range(int(numsLen / 2)):
            
            answer.append(pos[i])
            answer.append(neg[i])
        
        return answer
        
        
        
        
        