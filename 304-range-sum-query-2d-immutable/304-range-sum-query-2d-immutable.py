class NumMatrix:
    A = None
    def __init__(self, matrix: List[List[int]]):
        self.A = [[0 for x in range(len(matrix[0]))] for y in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                self.A[i][j] = matrix[i][j]
                if i > 0:
                    self.A[i][j] += self.A[i - 1][j]
                if j > 0:
                    self.A[i][j] += self.A[i][j - 1]
                if i > 0 and j > 0:
                    self.A[i][j] -= self.A[i - 1][j - 1]
                    
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        ret = self.A[row2][col2]
        if row1 > 0:
            ret -= self.A[row1 - 1][col2]
        if col1 > 0:
            ret -= self.A[row2][col1 - 1]
        if row1 > 0 and col1 > 0:
            ret += self.A[row1 -1][col1 - 1]
        return ret


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)