class Solution {
private:
    vector<vector<int>> ret;
    void solve(vector<int>& candidates, vector<int>& v, int pos, int sum, const int& target) {
        if (sum > target) return;
        if (sum == target) {
            ret.push_back(v);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            v.push_back(candidates[i]);
            solve(candidates, v, i, sum + candidates[i], target);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        solve(candidates, v, 0, 0, target);
        return ret;
    }
};