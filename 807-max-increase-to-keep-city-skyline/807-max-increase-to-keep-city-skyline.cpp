class Solution {
public:
    int len;
    
    int findHeight(vector<vector<int>>& grid, int row, int col) {
        
        int val = grid[row][col];
        int rowMax = val, colMax = val;
        
        for (int i = 0; i < len; i++) {
            if (grid[row][i] > rowMax)
                rowMax = grid[row][i];
            if (grid[i][col] > colMax)
                colMax = grid[i][col];
        }
        
        return min(rowMax, colMax);
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        len = grid.size();
        int answer = 0;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                answer += findHeight(grid, i, j) - grid[i][j];
            }
        }
        
        return answer;
    }
};
