class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        height = len(grid)
        width = len(grid[0])
        
        for i in range(height):
            for j in range(width):
                
                if i == 0 and j == 0: continue
                elif i == 0: grid[i][j] += grid[i][j - 1]
                elif j == 0: grid[i][j] += grid[i - 1][j]
                else: grid[i][j] += min(grid[i - 1][j], grid[i][j - 1])
                    
        return grid[height - 1][width - 1]
        