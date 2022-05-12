class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        nums.sort()
        numsLen = len(nums)
        
        visited = [False for i in range(numsLen)]
        answer = []
        
        def solve(array): # no return
            
            if len(array) == numsLen:
                answer.append(array.copy())
                
            for i in range(0, numsLen):
                
                if visited[i]:
                    continue
                if i and nums[i] == nums[i - 1] and not visited[i - 1]:
                    continue
                
                array.append(nums[i])
                visited[i] = True
                
                solve(array)
                array.pop()
                visited[i] = False
                
        solve([])
        
        return answer