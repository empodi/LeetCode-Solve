class Solution {
public:
    int height;
    int width;
    int moving[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void DFS(vector<vector<char>>& board, int i, int j) {
           
        if (board[i][j] != 'O') return;
        
        board[i][j] = '*';
        
        for (int k = 0; k < 4; k++) {
            int x = i + moving[k][0];
            int y = j + moving[k][1];
            
            if (x < 0 || y < 0 || x >= height || y >= width) continue;
            
            DFS(board, x, y);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        height = board.size();
        width = board[0].size();
        
        for (int i = 0; i < width; i++) {
            DFS(board, 0, i);
            DFS(board, height - 1, i);
        }
        for (int i = 0; i < height; i++) {
            DFS(board, i, 0);
            DFS(board, i, width - 1);
        }
        
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++) {
                cout << board[i][j];
            }
            cout << endl;
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