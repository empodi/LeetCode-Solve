class Solution {
private:
    bool check[10];
    vector<vector<int>> ret;
    void solve(vector<int>& nums, vector<int>& v) {
        if (v.size() == nums.size()) {
            ret.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (check[i]) continue;
            v.push_back(nums[i]); check[i] = true;
            solve(nums, v);
            v.pop_back(); check[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        memset(check, false, sizeof(check));
        vector<int> v;
        solve(nums, v);
        return ret;
    }
};