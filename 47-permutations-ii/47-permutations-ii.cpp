class Solution {
public:
    vector<vector<int>> ret;
    bool visited[8];
    int len;
    
    void helper(vector<int>& nums, vector<int>& v) {
        
        for (int i = 0; i < len; i++) {
            
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            
            v.push_back(nums[i]);
            visited[i] = true;
            
            if (v.size() == len) ret.push_back(v);
            else helper(nums, v);
            
            v.pop_back();
            visited[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    
        len = nums.size();
        
        if (len == 1) {
            ret.push_back(nums);
            return ret;
        }
        
        sort(nums.begin(), nums.end());    
        
        for (int i = 0; i < len; i++) {
            
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            memset(visited, false, sizeof(visited));
            
            vector<int> v;
            v.push_back(nums[i]);
            visited[i] = true;
            helper(nums, v);
        }
        
        return ret;
    }
};