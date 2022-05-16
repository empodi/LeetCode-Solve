typedef pair<pair<int,int>,int> pii;

class Solution {
public:
    bool visited[101][101];
    int height;
    int width;
    
    int moving[8][2] = { {1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1},{0,1},{0,-1} };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        height = grid.size();
        width = grid[0].size();
        int answer = INT_MAX;
        
        queue<pii> q;
        
        if (grid[0][0] == 0)
            q.push({{0,0},1});
        
        while (!q.empty()) {
            
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            if (x == height - 1 && y == width - 1) {
                answer = answer < dist ? answer : dist;
                continue;
            }
            
            for (int k = 0; k < 8; k++) {
                int nx = x + moving[k][0];
                int ny = y + moving[k][1];
                
                if (nx < 0 || ny < 0 || nx >= height || ny >= width) 
                    continue;
                if (grid[nx][ny] == 1 || visited[nx][ny]) 
                    continue;
                
                visited[nx][ny] = true;
                q.push({{nx, ny}, dist + 1});
            }
        }
        
        return answer = (answer == INT_MAX) ? -1: answer;
    }
};