class Solution {
public:
    vector<vector<int>> ret;
    int len;
    
    void helper(vector<int>& nums, vector<int>& v) {
        
        for (int i = 0; i < len; i++) {
            
            if (nums[i] == 100) continue;
            v.push_back(nums[i]);
            int tmp = nums[i];
            nums[i] = 100;
            
            if (v.size() == len) ret.push_back(v);
            else helper(nums, v);
            
            v.pop_back();
            nums[i] = tmp;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        len = nums.size();
        vector<int> v;
     
        helper(nums, v);
        return ret;
    }
};