class Solution {
public:
    int width;
    int height;
    
    bool helper(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        
        if (idx + 1 == word.length() && board[i][j] == word[idx]) {
            return true;
        } 
        
        if (board[i][j] != word[idx]) return false;
        
        char ch = board[i][j];
        board[i][j] = '*';
        
        bool a = false, b = false, c = false, d = false;
        
        if (i > 0) a = helper(board, word, i - 1, j, idx + 1);
        if (j > 0) b = helper(board, word, i, j - 1, idx + 1);
        if (i + 1 < height) c = helper(board, word, i + 1, j, idx + 1);
        if (j + 1 < width) d = helper(board, word, i, j + 1, idx + 1);
        
        board[i][j] = ch;
        
        return a || b || c || d;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        height = board.size();
        width = board[0].size();
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == word[0]) {
                    
                    if (word.length() == 1)
                        return true;

                    if (helper(board, word, i, j, 0))
                        return true;
                }
            }
        }
        
        return false;
    }
};