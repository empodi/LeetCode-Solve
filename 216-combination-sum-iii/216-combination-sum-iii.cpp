class Solution {
public:
    vector<vector<int>> answer;
    
    void solve(vector<int>& v, int cur, int sum, int& k, int& n) {
        
        if (sum > n) return;
        
        if (v.size() == k) {
            if (sum == n) 
                answer.push_back(v);
            return;
        }

        for (int i = cur; i < min(n, 10); i++) {
            
            v.push_back(i);
            solve(v, i + 1, sum + i, k, n);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> v;
        
        solve(v, 1, 0, k, n);
        
        return answer;   
    }
};