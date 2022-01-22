class Solution {
public:
    int width;
    int height;
    int moving[4][2] ={{0,1},{0,-1},{1,0},{-1,0}};
    bool visited[6][6];
    
    bool helper(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        
        if (board[i][j] != word[idx]) return false; 
        if (idx + 1 == word.length()) return true;
        
        char tmp = board[i][j];
        board[i][j] = '*';
        
        bool ret = false;
        
        for (int k = 0; k < 4; k++) {
            int x = i + moving[k][0];
            int y = j + moving[k][1];
            
            if (x >= 0 && y >= 0 && x < height && y < width && !visited[x][y])
                ret = ret || helper(board, word, x, y, idx + 1);
        } 
                
        board[i][j] = tmp;
        
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        height = board.size();
        width = board[0].size();
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == word[0]) {
                    
                    if (word.length() == 1)
                        return true;
                    
                    //memset(visited, false, sizeof(visited));
                    if (helper(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};