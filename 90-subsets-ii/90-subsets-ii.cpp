class Solution {
public:
    vector<vector<int>> ret;
    
    void solve(vector<int>& nums, vector<int>& v, int idx) {
        
        ret.push_back(v);
        
        for (int i = idx; i < nums.size(); i++) {
            
            if (i > idx && nums[i] == nums[i - 1]) continue;
            
            v.push_back(nums[i]);
            solve(nums, v, i + 1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> v;
        solve(nums, v, 0);
        
        return ret;
    }
};