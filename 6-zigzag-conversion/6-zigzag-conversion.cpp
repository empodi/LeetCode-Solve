class Solution {
public:
    
    string convert(string s, int numRows) {
        
        if (numRows == 1) {
            return s;
        }
        
        vector<vector<char>> v(numRows, vector<char>{});
        
        int idx = 0;
        int sLen = s.length();
        bool flag = true;
        string answer = "";
        
        for (int i = 0; i < sLen; i++) {
            
            v[idx].push_back(s[i]);
            
            if (flag) idx++;
            else idx--;
            
            if (idx == numRows) {
                idx = numRows - 2;
                flag = false;
            }
            else if (idx == -1) {
                idx = 1;
                flag = true;
            }
        }    
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                answer += v[i][j];
            }
        }
        
        return answer;
    }
};