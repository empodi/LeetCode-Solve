class Solution {
private:
    int height;
    int width;
    bool visited[101][101];
    int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        height = grid.size();
        width = grid[0].size();
        
        int answer = 0;
        int cnt = 0;
        queue<pair<int,int>> q;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j]) {
                    cnt++;
                    q.push({i,j});
                }
            }
        }
        
        if (cnt == 0 || cnt == height * width)
            return -1;

        while (!q.empty()) {
            
            int qLen = q.size();
            answer++;
            
            while (qLen--) {
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = x + moving[i][0];
                    int ny = y + moving[i][1];
                    
                    if (nx < 0 || ny < 0 || nx >= height || ny >= width || grid[nx][ny])
                        continue;
                    
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return answer - 1;
    }
};