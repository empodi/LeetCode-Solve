class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int height = mat.size();
        int width = mat[0].size();
        vector<vector<int>> ret(height, vector<int>(width, 0));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) mat[i][j] += mat[i][j - 1];
                else if (j == 0) mat[i][j] += mat[i - 1][j];
                else mat[i][j] += (mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1]);
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int ax = i - k < 0 ? 0 : i - k;
                int bx = i + k >= height ? height - 1 : i + k;
                int ay = j - k < 0 ? 0 : j - k;
                int by = j + k >= width ? width - 1 : j + k;
                if (ax == 0 && ay == 0) ret[i][j] = mat[bx][by];
                else if (ax == 0) ret[i][j] = mat[bx][by] - mat[bx][ay - 1];
                else if (ay == 0) ret[i][j] = mat[bx][by] - mat[ax - 1][by];
                else ret[i][j] = mat[bx][by] - mat[ax - 1][by] - mat[bx][ay - 1] + mat[ax - 1][ay - 1];
            }
        }
        return ret;
    }
};