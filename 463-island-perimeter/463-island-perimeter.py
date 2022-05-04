class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        
        answer = 0
        height = len(grid)
        width = len(grid[0])
        
        moving = [[0,1],[0,-1],[1,0],[-1,0]]
        
        def solve(x, y) -> int:
            
            grid[x][y] = 2
            
            perimeter = 0
            
            for i in range(4):
                nx, ny = (x + moving[i][0], y + moving[i][1])
                
                if nx < 0 or ny < 0 or nx >= height or ny >= width:
                    perimeter += 1
                elif grid[nx][ny] == 0:
                    perimeter += 1
                elif grid[nx][ny] == 1:
                    perimeter += solve(nx, ny)
            
            return perimeter
        
        for i in range(height):
            for j in range(width):
                if grid[i][j] == 1:
                    answer = solve(i, j)
                    
        return answer