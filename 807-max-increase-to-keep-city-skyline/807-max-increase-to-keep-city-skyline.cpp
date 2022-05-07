class Solution {
public:
    int len;
    int rowMax[51];
    int colMax[51];
    
    void setMax(vector<vector<int>>& grid) {
        
        for (int i = 0; i < len; i++) {
            
            int rowVal = grid[i][0];
            int colVal = grid[0][i];
            
            for (int j = 1; j < len; j++) {
                rowVal = rowVal > grid[i][j] ? rowVal : grid[i][j];
                colVal = colVal > grid[j][i] ? colVal : grid[j][i];
            }
            
            rowMax[i] = rowVal;
            colMax[i] = colVal;
        }
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        len = grid.size();
        int answer = 0;
        
        setMax(grid);
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                answer += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        
        return answer;
    }
};
