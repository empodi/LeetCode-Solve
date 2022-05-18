class Solution {
private:
    int height;
    int width;
    int moving[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
public:
    bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y) {
        
        if (x < 0 || y < 0 || x >= height || y >= width || grid2[x][y] == 0) 
            return true;
        if (grid1[x][y] == 0 || grid2[x][y] == -1) 
            return false;
        
        bool flag = true;
        grid2[x][y] = 0;
        
        for (int k = 0; k < 4; k++) {
            flag = DFS(grid1, grid2, x + moving[k][0], y + moving[k][1]);
            if (!flag) break;
        }
        
        if (!flag) grid2[x][y] = -1;
        
        return flag;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        height = grid1.size();
        width = grid1[0].size();
        
        int answer = 0;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                
                if (grid2[i][j] == 1 && grid1[i][j] == 1) {
                    if (DFS(grid1, grid2, i, j))
                        answer++;
                }
            }
        }
        
        return answer;
    }
};