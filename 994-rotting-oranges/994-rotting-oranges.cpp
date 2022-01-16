class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        int height = grid.size(), width = grid[0].size(), cnt = 0, ans = 0;
        bool isOne = false;
        
        for (int i = 0 ; i < height; i++) {
            for (int j = 0 ; j < width; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    cnt++;
                }
                if (grid[i][j] == 1) isOne = true;
            }
        }
        if (!isOne) return 0;
        
        while (!q.empty()) {
            
            int push = 0;
            for (int i = 0; i < cnt; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                grid[x][y] = 0;
                if (x > 0 && grid[x - 1][y] == 1) {
                    q.push(make_pair(x - 1, y));
                    grid[x - 1][y] = 0;
                    push++;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    q.push(make_pair(x, y - 1));
                    grid[x][y - 1] = 0;
                    push++;
                }
                if (x + 1 < height && grid[x + 1][y] == 1) {
                    q.push(make_pair(x + 1, y));
                    grid[x + 1][y] = 0;
                    push++;
                }
                if (y + 1 < width && grid[x][y + 1] == 1) {
                    q.push(make_pair(x, y + 1));
                    grid[x][y + 1] = 0;
                    push++;
                }
            }
            if (push > 0) ans++;
            cnt = push;
            
        }
        
        for (int i = 0; i < height; i++) 
            for (int j = 0; j < width; j++)
                if (grid[i][j] == 1) return -1;
        
        return ans;
        
    }
};