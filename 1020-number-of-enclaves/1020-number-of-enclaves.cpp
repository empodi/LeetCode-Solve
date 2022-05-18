class Solution {
private:
    int height;
    int width;
    int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
public:
    void floodFillEdge(vector<vector<int>>& grid, int x, int y) {
        
        if (x < 0 || y < 0 || x >= height || y >= width || !grid[x][y])
            return;
        
        grid[x][y] = 0;
        
        for (int i = 0; i < 4; i++) {
            floodFillEdge(grid, x + moving[i][0], y + moving[i][1]);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        height = grid.size();
        width = grid[0].size();
        
        int answer = 0;
        
        for (int i = 0; i < height; i++) {
            if (grid[i][0]) floodFillEdge(grid, i, 0);
            if (grid[i][width - 1]) floodFillEdge(grid, i, width - 1);
        }
        
        for (int i = 0; i < width; i++) {
            if (grid[0][i]) floodFillEdge(grid, 0, i);
            if (grid[height - 1][i]) floodFillEdge(grid, height - 1, i);
        }
        
        for (auto row : grid)
            for (auto elem: row) 
                if (elem)
                    answer += 1;
        
        return answer;
    }
};