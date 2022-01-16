class Solution {
public:
    int width;
    int height;
    bool flag = false;
    
    void helper(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        
        if (idx + 1 == word.length() && board[i][j] == word[idx]) {
            flag = true;
            return;
        }
        
        if (board[i][j] != word[idx]) return;
        
        char c = board[i][j];
        board[i][j] = '*';
        
        if (i > 0) helper(board, word, i - 1, j, idx + 1);
        if (j > 0) helper(board, word, i, j - 1, idx + 1);
        if (i + 1 < height) helper(board, word, i + 1, j, idx + 1);
        if (j + 1 < width) helper(board, word, i, j + 1, idx + 1);
        
        board[i][j] = c;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        height = board.size();
        width = board[0].size();
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == word[0]) {
                    
                    if (word.length() == 1)
                        return true;

                    helper(board, word, i, j, 0);
                    if (flag) return flag;
                }
            }
        }
        
        return flag;
    }
};