inline int MAX(int a,int b) {return a>b ? a:b;}
inline int MIN(int a,int b) {return a<b ? a:b;}
class Solution {
private:
    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (MIN(x,y) < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        int area = 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            area += dfs(grid, nx, ny);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j])
                    answer = MAX(answer,dfs(grid,i,j));
            }
        }
        return answer;
    }
};