class Solution:
    def pacificAtlantic(self, grid: List[List[int]]) -> List[List[int]]:
        
        answer = []
        height, width = len(grid), len(grid[0])
        movs = [ [1,0],[-1,0],[0,1],[0,-1] ]
        
        p = [[False for col in range(width)] for row in range(height)]
        c = [[False for col in range(width)] for row in range(height)]
        
        def solve(island: List[List[int]], x: int, y: int): # no return
            
            if island[x][y]: 
                return
            
            island[x][y] = True
            
            if p[x][y] and c[x][y]:
                answer.append([x, y])
            for mov in movs:
                nx, ny = x + mov[0], y + mov[1]
                
                if nx < 0 or ny < 0 or nx >= height or ny >= width or island[nx][ny]:
                    continue
                if grid[x][y] <= grid[nx][ny]:
                    solve(island, x + mov[0], y + mov[1])
        
        for i in range(height):
            solve(p, i, 0)
        for i in range(width):
            solve(p, 0, i)
        for i in range(height):
            solve(c, i, width -1)
        for i in range(width):
            solve(c, height - 1, i)
        
        return answer
    