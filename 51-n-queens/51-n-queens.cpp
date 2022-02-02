class Solution {
public:
    vector<vector<string>> ret;
    
    bool promising(vector<int>& v, int idx) {
        
        for (int k = 1; k < idx; k++) {
            if (v[idx] == v[k] || abs(v[idx] - v[k]) == idx - k)
                return false;
        }
        return true;
    }
    
    void helper(vector<int>& v, int pos, int len) {
        
        if (promising(v, pos)) {
            
            if (pos == len) {
                vector<string> vs;
                for (int i = 1; i <= len; i++) {
                    string str;
                    for (int j = 1; j <= len; j++) {
                        if (j == v[i]) str += "Q";
                        else str += ".";
                    }
                    vs.push_back(str);
                }
                ret.push_back(vs);
            }
            else {
                for (int i = 1; i <= len; i++) {
                    v[pos + 1] = i;
                    helper(v, pos + 1, len);
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<int> v(n + 1);
        
        helper(v, 0, n);
        
        return ret;
    }
};