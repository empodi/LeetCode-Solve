class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if (triangle.size() == 1) return triangle[0][0];
        
        int len = triangle.size();
        
        for (int i = 1; i < len; i++) {
            
            for (int j = 0; j <= i; j++) {
                
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }
        
        int ret = 111111;
        
        for (int i = 0; i < len; i++) {
            ret = min(ret, triangle[len - 1][i]);
        }
        
        return ret;
    }
};