class Solution {
private:
    int height;
    int width;
    int moving[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    
    void BFS(int i, int j, vector<vector<char>>& grid) {
        
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        
        while (!q.empty()) {
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                
                int nx = x + moving[k][0];
                int ny = y + moving[k][1];
                
                if (nx < 0 || ny < 0 || nx >= height || ny >= width) continue;
                if (grid[nx][ny] == '0') continue;
                
                q.push({nx, ny});
                grid[nx][ny] = '0';
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        
        height = grid.size();
        width = grid[0].size();
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
             
                if (grid[i][j] == '0') continue;
                
                cnt++;
                BFS(i, j, grid);
            }
        }
        
        return cnt;
    }
};