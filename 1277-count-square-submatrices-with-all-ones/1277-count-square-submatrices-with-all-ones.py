class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        
        height = len(matrix)
        width = len(matrix[0])
        
        answer = 0
        
        for i in range(height):
            for j in range(width):
                
                if matrix[i][j] == 0:
                    continue
                
                if i == 0 or j == 0:
                    answer += 1
                    continue
                
                matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1])
                
                answer += matrix[i][j]
                
        return answer
                
                    
                

                    