class Solution {
public:
    int height;
    int width;
    
    int dp[210][210];
    int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    
    void setDP() {
        
        for (int i = 0; i < height; i++) 
            for (int j = 0; j < width; j++) 
                dp[i][j] = -1;
    }
    
    int find(vector<vector<int>>& matrix, int x, int y) {    
        
        int val = 1;
        
        for (int k = 0; k < 4; k++) {
            
            int nx = x + moving[k][0];
            int ny = y + moving[k][1];
            
            if (nx < 0 || ny < 0 || nx >= height || ny >= width) continue;
            if (matrix[nx][ny] <= matrix[x][y]) continue;
            
            if (dp[nx][ny] > 0) {
                val = max(val, dp[nx][ny] + 1);
            }
            else {
                val = max(val, find(matrix, nx, ny) + 1);
            }
        }
        
        dp[x][y] = val;
        return val;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        height = matrix.size();
        width = matrix[0].size();
        
        setDP();
        
        int ans = 0;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                ans = max(ans, find(matrix, i, j));
            }
        }
    
        return ans;
    }
};