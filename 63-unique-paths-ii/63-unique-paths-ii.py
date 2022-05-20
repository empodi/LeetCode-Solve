class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        height, width = len(grid), len(grid[0])
        hflag, wflag = True, True
        route = [[0 for col in range(width)] for row in range(height)]
    
        for i in range(height):
            if grid[i][0] == 0 and hflag:
                route[i][0] = 1
            else:
                hflag = False
                route[i][0] = 0
                
        for i in range(width):
            if grid[0][i] == 0 and wflag:
                route[0][i] = 1
            else:
                wflag = False
                route[0][i] = 0

        for i in range(1, height):
            for j in range(1, width):
                if not grid[i][j]:   
                    if route[i - 1][j] and route[i][j - 1]:
                        route[i][j] = route[i - 1][j] + route[i][j - 1]
                    else:
                        route[i][j] = max(route[i - 1][j], route[i][j - 1])
        """            
        for row in route:
            for val in row:
                print(val, end=" ")
            print()
        """
        return route[height - 1][width - 1]
        