class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        tr = [[0 for x in range(len(matrix))] for y in range(len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                tr[j][i] = matrix[i][j]
        return tr