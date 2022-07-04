class Solution {
private:
    vector<vector<int>> ret;
    int target;
    int len;
    void solve(vector<int>& v, int cur, int sum) {
        if (sum > target || cur > target || v.size() > len) return;
        if (v.size() == len && sum == target) {
            ret.push_back(v);
            return;
        }
        for (int i = cur; i < 10; i++) {
            v.push_back(i);
            solve(v, i + 1, sum + i);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        target = n;
        len = k;
        solve(v, 1, 0);
        return ret;
    }
};