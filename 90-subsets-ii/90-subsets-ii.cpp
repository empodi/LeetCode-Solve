class Solution {
private:
    vector<vector<int>> ret;
    void solve(vector<int>& nums, vector<int>& v, int pos) {
        ret.push_back(v);
        for (int i = pos; i < nums.size(); i++) {
            v.push_back(nums[i]);
            solve(nums, v, i + 1);
            v.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        solve(nums, v, 0);
        return ret;
    }
};