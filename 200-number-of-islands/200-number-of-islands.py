class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        height = len(grid)
        width = len(grid[0])
        
        moving = [ [1,0], [-1,0], [0,1], [0,-1] ]
        
        answer = 0
        
        for i in range(height):
            for j in range(width):
                
                if grid[i][j] == "0":
                    continue
                    
                answer += 1
                
                queue = [[i, j]]
                grid[i][j] = "0"
                
                while queue:
                    x, y = (queue[0][0], queue[0][1])
                    queue.pop(0)
                    
                    for mov in moving:
                        nx, ny = (x + mov[0], y + mov[1])
                
                        if nx < 0 or ny < 0 or nx >= height or ny >= width:
                            continue
                        if grid[nx][ny] == "0":
                            continue
                            
                        grid[nx][ny] = "0"
                        queue.append([nx, ny])
                    
        return answer
            
            
        