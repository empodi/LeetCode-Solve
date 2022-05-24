class Solution {
private:
    int len;
    int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    void flood(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= len || j >= len) return;
        if (grid[i][j] == 0 || grid[i][j] == 2) return;
        grid[i][j] = 2;
        for (int d = 0; d < 4; d++) {
            flood(grid, i + dir[d][0], j + dir[d][1]);
        }
    }
    bool expand(vector<vector<int>>& grid, int i, int j, const int& edge) {
        if (i < 0 || j < 0 || i >= len || j >= len) return false;
        grid[i][j] = grid[i][j] == 0 ? edge + 1 : grid[i][j];
        return grid[i][j] == 1;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        len = grid.size();
        int answer = 0;
        
        for (int i = 0, flag = 1; i < len && flag; i++){
            for (int j = 0; j < len && flag; j++) {
                if (grid[i][j]) {
                    flood(grid, i, j);
                    flag = 0;
                }
            }
        }
        
        for (int edge = 2; !answer ;edge++) {
            for (int i = 0; !answer && i < len; i++) {
                for (int j = 0; !answer && j < len; j++) {
                    if (grid[i][j] == edge && (expand(grid, i - 1, j, edge) || 
                            expand(grid, i + 1, j ,edge) || 
                            expand(grid, i, j - 1, edge) || 
                            expand(grid, i, j + 1, edge))) {
                        answer = edge - 2;
                    }
                }
            }
        }
        
        return answer;
    }
};