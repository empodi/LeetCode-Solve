class Solution {
private:    
    int height;
    int width;
    int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
public:
    bool solve(vector<vector<int>>& grid ,int i, int j) {
        
        if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
            return false;
        
        bool flag = true;
        
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = 1;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + moving[k][0];
                int ny = y + moving[k][1];
                
                if (nx < 0 || ny < 0 || nx >= height || ny >= width) 
                    continue;
                if (grid[nx][ny] == 1)
                    continue;
                
                if (nx == 0 || ny == 0 || nx == height - 1 || ny == width - 1)
                    flag = false;
                
                grid[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        
        return flag;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        height = grid.size();
        width = grid[0].size();
        
        int answer = 0;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                
                if (grid[i][j] == 0 && solve(grid, i, j))
                    answer++;
            }
        }
        
        return answer;
    }
};