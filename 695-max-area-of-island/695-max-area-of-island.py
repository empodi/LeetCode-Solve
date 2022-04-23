class Solution:
    # 파이썬 함수 argument???
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        maxArea = 0
        
        height = len(grid)
        width = len(grid[0])
        moving = [[0,1],[0,-1],[1,0],[-1,0]]
        
        for i in range(height):
            for j in range(width):
                
                if grid[i][j] == 0: continue
                
                grid[i][j] = 0
                
                localArea = 1
                queue = deque([(i, j)])
                
                while queue:
                    elem = queue.popleft()
                    x = elem[0]
                    y = elem[1]
                    
                    for k in moving:
                        nx = k[0] + x
                        ny = k[1] + y
                        
                        if nx < 0 or ny < 0 or nx >= height or ny >= width:
                            continue
                        if grid[nx][ny] == 0: 
                            continue
                        
                        grid[nx][ny] = 0
                        queue.append((nx, ny))
                        
                        localArea = localArea + 1
                
                maxArea = max(maxArea, localArea)
                
        return maxArea