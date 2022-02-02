class Solution {
public:
    int ret = 0;
    
    bool promising (vector<int>& v, int idx) {
        
        for (int k = 1; k < idx; k++) {
            if (v[idx] == v[k] || abs(v[idx] - v[k]) == idx - k)
                return false;
        }
        return true;
    }
    
    void helper (vector<int>& v, int pos, int len) {
        
        if (promising(v, pos)) {
            if (pos == len) 
                ret++;
            else {
                for (int i = 1; i <= len; i++) {
                    v[pos + 1] = i;
                    helper(v, pos + 1, len);
                }  
            }
        }
    }
    
    int totalNQueens(int n) {
        
        vector<int> v(n + 1);
        
        helper(v, 0, n);
        
        return ret;
    }
};