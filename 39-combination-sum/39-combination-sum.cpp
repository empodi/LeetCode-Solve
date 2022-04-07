class Solution {
private:
    vector<vector<int>> ret;
    int tg;
    int len;
    
    void solve(vector<int>& candidates, vector<int>& v, int sum, int idx) {
        
        if (sum > tg) return;
        
        if (sum == tg) {
            ret.push_back(v);
        }
        
        for (int i = idx; i < len; i++) {
            v.push_back(candidates[i]);
            solve(candidates, v, sum + candidates[i], i);
            v.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        tg = target;
        len = candidates.size();
        
        vector<int> v;
        
        solve(candidates, v, 0, 0);
        
        return ret;
    }
};