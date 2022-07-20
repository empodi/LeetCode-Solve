class Solution {
private:
    int sums[101][101] = {0,};
    int height, width;
    void copy_matrix(vector<vector<int>>& matrix) {
        height = matrix.size(); width = matrix[0].size();
        for (int i = 0; i < height; i++) 
            for (int j = 0; j < width; j++)
                sums[i + 1][j + 1] = matrix[i][j];
    }
    void set_sums() {
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {
                sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        copy_matrix(matrix);
        set_sums();
        int answer = 0;
        
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= width; j++) {

                for (int k = i; k <= height; k++) {
                    for (int p = j; p <= width; p++) {
                        if (sums[k][p] - sums[i - 1][p] - sums[k][j - 1] + sums[i - 1][j - 1] == target)
                            answer++;
                    }
                }
            }
        }
        return answer;
    }
};