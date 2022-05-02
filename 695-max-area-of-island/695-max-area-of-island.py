class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        maxArea = 0
        height = len(grid)
        width = len(grid[0])
        
        moving = [[0,1],[0,-1],[1,0],[-1,0]]
        
        def solve_dfs(x, y) -> int:
            
            if grid[x][y] == 0: return 0
            
            grid[x][y] = 0
            
            retArea = 1
            
            for mov in moving:
                nx = x + mov[0]
                ny = y + mov[1]
                
                if nx < 0 or ny < 0 or nx >= height or ny >= width:
                    continue
                
                retArea += solve_dfs(nx, ny)
            
            return retArea
            
        for i in range(height):
            for j in range(width):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, solve_dfs(i, j))        

        return maxArea
