class Solution {
private:
    vector<vector<int>> ret;
    void solve(vector<int>& cands, vector<int>& v, int pos, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            ret.push_back(v);
            return;
        }
        for (int i = pos; i < cands.size(); i++) {
            if (target < cands[i]) break;
            //if (i > pos && cands[i] == cands[i - 1]) continue;
            v.push_back(cands[i]); 
            solve(cands, v, i + 1, sum + cands[i], target);
            v.pop_back(); 
            while (i < cands.size() - 1 && cands[i] == cands[i + 1]) i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        solve(candidates, v, 0, 0, target);
        return ret;
    }
};
// [1,2,2,2,5]