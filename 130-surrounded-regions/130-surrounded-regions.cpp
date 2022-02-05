class Solution {
public:
    bool visited[201][201];
    int height;
    int width;
    int moving[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void helper(vector<vector<char>>& board, int i, int j) {

        if (visited[i][j]) return;
        
        visited[i][j] = true;
        board[i][j] = '*';
        
        for (int k = 0; k < 4; k++) {
            int x = i + moving[k][0];
            int y = j + moving[k][1];
            
            if (x < 0 || y < 0 || x >= height || y >= width) continue;
            if (board[x][y] == 'X' || visited[x][y]) continue;
            
            helper(board, x, y);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        memset(visited, false, sizeof(visited));
        
        height = board.size();
        width = board[0].size();
        
        for (int i = 0; i < width; i++) {
            
            if (!visited[0][i] && board[0][i] == 'O')
                helper(board, 0, i);
            
            if (!visited[height - 1][i] && board[height - 1][i] == 'O')
                helper(board, height - 1, i);
        }
        
        for (int i = 0; i < height; i++) {
            
            if (!visited[i][0] && board[i][0] == 'O')
                helper(board, i, 0);
            
            if (!visited[i][width - 1] && board[i][width - 1] == 'O')
                helper(board, i, width - 1);
        }
        
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        
    }
};



/*
OOOOXX
OOOOOO
OXOXOO
OXOOXO
OXOXOO
OXOOOO


XXXX
XOOX
XXOX
XOXX
*/