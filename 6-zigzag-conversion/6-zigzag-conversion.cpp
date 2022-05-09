class Solution {
public:
    char words[1001][1001];
    
    string convert(string s, int numRows) {
        
        if (numRows == 1) {
            return s;
        }
        
        memset(words, '#', sizeof(words));
        
        int col = 0;
        int sLen = s.length();
        int curRow = 0;
        string answer = "";
        
        int i = 0;
        while (i < sLen) {
            
            words[curRow][col] = s[i];
            i++;
            curRow++;
            
            if (curRow == numRows) {
                curRow = numRows - 1;
                
                while (i < sLen) {
                    curRow--;
                    col++;
                    words[curRow][col] = s[i];
                    if (curRow == 0) break;
                    i++;
                }
            }
        }
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < 1001; j++) {
                if (words[i][j] != '#') {
                    answer += words[i][j];
                    //cout << words[i][j] << " ";
                    if (answer.length() == sLen) 
                        break;
                }
            }
        }
        return answer;
    }
};