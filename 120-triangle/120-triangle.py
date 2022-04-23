class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        tLen = len(triangle)
        
        if (tLen == 1): return triangle[0][0];
        
        for i, row in enumerate(triangle):
            
            if i == 0: continue;
            
            for j, val in enumerate(row):
                
                if j == 0: row[j] += triangle[i - 1][j]
                elif i == j: row[j] += triangle[i - 1][j - 1]
                else: 
                    row[j] += min(triangle[i - 1][j - 1], triangle[i - 1][j])
                    
        return min(triangle[tLen - 1])
            
                    
    
    