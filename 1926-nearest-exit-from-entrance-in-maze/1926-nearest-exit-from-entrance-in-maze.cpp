typedef pair<int, int> pii;
class Solution {
private:
    int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int height = maze.size();
        int width = maze[0].size();
        int answer = -1;
        queue<pair<pii,int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+';
        
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second + 1;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + moving[i][0];
                int ny = y + moving[i][1];
                if (nx < 0 || ny < 0 || nx >= height || ny >= width || maze[nx][ny] == '+')
                    continue;
                if (nx == 0 || ny == 0 || nx == height - 1 || ny == width - 1) {
                    if (answer >= 0) {
                        answer = min(answer, dist);
                    }
                    else {
                        answer = dist;
                    }
                }
                maze[nx][ny] = '+';
                q.push({{nx, ny}, dist});
            }
        }
        return answer;
    }
};