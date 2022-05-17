class Solution {
private:    
    int height;
    int width;
    int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
public:
    void floodFill(vector<vector<int>>& grid, int x, int y) {
        
        if (x < 0 || y < 0 || x >= height || y >= width || grid[x][y])
            return;
        
        grid[x][y] = 1;
        
        for (int i = 0; i < 4; i++) {
            floodFill(grid, x + moving[i][0], y + moving[i][1]);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        height = grid.size();
        width = grid[0].size();
        
        int answer = 0;
        
        for (int i = 0; i < height; i++) {
            if (!grid[i][0]) 
                floodFill(grid, i, 0);
            if (!grid[i][width - 1]) 
                floodFill(grid, i, width - 1);
        }
        
        for (int i = 0; i < width; i++) {
            if (!grid[0][i]) 
                floodFill(grid, 0, i);
            if (!grid[height - 1][i]) 
                floodFill(grid, height - 1, i);
        }
        
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                
                if (grid[i][j] == 0) {
                    answer++;
                    floodFill(grid, i, j);
                }
            }
        }
        
        return answer;
    }
};