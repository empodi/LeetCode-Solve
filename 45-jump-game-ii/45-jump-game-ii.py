class Solution:
    def jump(self, nums: List[int]) -> int:
        
        numsLen = len(nums)
        
        jmp = [987654321 for x in range(numsLen)]
        jmp[0] = 0
        
        for pos in range(0, numsLen):
            
            for i in range(pos + 1, min(pos + nums[pos] + 1, numsLen)):
                jmp[i] = min(jmp[i], jmp[pos] + 1)
                
        print(jmp)
                
        return jmp[numsLen - 1]
        