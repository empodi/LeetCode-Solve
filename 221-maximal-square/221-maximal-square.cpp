class Solution {
private:
    int dp[301][301];
    
    int getMin(int a, int b, int c) {
        a = a < b ? a : b;
        return a < c ? a : c;
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int height = matrix.size();
        int width = matrix[0].size();
        
        int answer = 0;
        
        for (int i = 0; i < height; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = answer = 1;
            }
        }
        
        for (int i = 0; i < width; i++) {
            if (matrix[0][i] == '1') {
                dp[0][i] = answer = 1;
            }
        }
        
        for (int i = 1; i < height; i++) {
            for (int j = 1; j < width; j++) {
                
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = getMin(dp[i- 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
                    answer = max(dp[i][j], answer);
                }
            }
        }
        
        return answer * answer;
    }
};