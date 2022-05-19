class Solution:
    height = 0
    width = 0
    dp = None
    movings = [ [1,0],[-1,0],[0,1],[0,-1] ]
    
    def DFS(self, matrix: List[List[int]], x: int, y: int) -> int:
        
        if self.dp[x][y] > 0:
            return self.dp[x][y]
        
        self.dp[x][y] = 1
        maxDist = 0
        for moving in self.movings:
            nx, ny = x + moving[0], y + moving[1]
            
            if nx < 0 or ny < 0 or nx >= self.height or ny >= self.width:
                continue
            if matrix[nx][ny] <= matrix[x][y]:
                continue
            maxDist = max(maxDist, self.DFS(matrix, nx, ny))
            
        self.dp[x][y] += maxDist
        return self.dp[x][y]
        
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        
        self.height, self.width = len(matrix), len(matrix[0])
        self.dp = [[0 for col in range(self.width)] for row in range(self.height)]
        
        answer = 0
        for i in range(self.height):
            for j in range(self.width):
                answer = max(answer, self.DFS(matrix, i, j))
        return answer
            
        