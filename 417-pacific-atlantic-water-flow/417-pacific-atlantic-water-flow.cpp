class Solution {
public:
    int height;
    int width;
    int move[4][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}};
    
    void helper(vector<vector<int>>& nums, vector<vector<bool>>& v, int x, int y) {
        
        if (v[x][y]) return;
        
        v[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            int p = x + move[i][0];
            int q = y + move[i][1];
            
            if (p < 0 || q < 0 || p >= height || q >= width) continue;
            if (nums[p][q] >= nums[x][y])
                helper(nums, v, p, q);
        }
        
    } 
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<bool>> pacific;
        vector<vector<bool>> atlan;
        vector<vector<int>> ans;
        height = heights.size();
        width = heights[0].size();
        
        pacific.resize(height, vector<bool>(width, false));
        atlan.resize(height, vector<bool>(width, false));
        
        for (int i = 0; i < width; i++) {
            if (!pacific[0][i]) helper(heights, pacific, 0, i);
            if (!atlan[height - 1][i]) helper(heights, atlan, height - 1, i);
        }
        for (int i = 0; i < height; i++) {
            if (!pacific[i][0]) helper(heights, pacific, i, 0);
            if (!atlan[i][width - 1]) helper(heights, atlan, i, width - 1); 
        }
        
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                if (pacific[i][j] && atlan[i][j])
                    ans.push_back({i, j});
        
        return ans;
    }
};