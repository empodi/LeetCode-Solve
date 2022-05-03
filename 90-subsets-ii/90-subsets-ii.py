class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        answer = []
        numsLen = len(nums)
        nums.sort()
        
        def solve(subArray, curIdx):
            
            answer.append(subArray.copy())
            
            for i in range(curIdx, numsLen):
                
                if i > curIdx and nums[i] == nums[i - 1]:
                    continue
                
                subArray.append(nums[i])
                solve(subArray, i + 1)
                subArray.pop()
                
        solve([], 0)
        
        return answer