#define MAX 987654321
class Solution {
private:
    int height;
    int width;
    bool visited[101][101];
    int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    
    void BFS(vector<vector<int>>& grid, int i, int j) {
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{i, j}, 1});
        visited[i][j] = true;
        
        while (!q.empty()) {
            
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + moving[k][0];
                int ny = y + moving[k][1];
                
                if (nx < 0 || ny < 0 || nx >= height || ny >= width)
                    continue;
                if (visited[nx][ny] || grid[nx][ny] < dist)
                    continue;
                
                visited[nx][ny] = true;
                grid[nx][ny] = dist;
                q.push({{nx, ny}, dist + 1});
            }
        }
    }
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        height = grid.size();
        width = grid[0].size();
        
        int answer = 0;
        int cnt = 0;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j]) 
                    cnt++;
                grid[i][j] = grid[i][j] ? -1 : MAX;
            }
        }
        
        if (cnt == 0 || cnt == height * width)
            return -1;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] < 0) {
                    memset(visited, false, sizeof(visited));
                    BFS(grid, i, j);
                }
            }
        }
                    
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] < 0) 
                    continue;
                answer = max(answer, grid[i][j]);
            }
        }
        
        return answer;
    }
};