class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ret(2, -1);
        
        int len = nums.size();
        
        if (len == 0) return ret;
        
        auto it = lower_bound(nums.begin(), nums.end(), target);
        
        if (it == nums.end() || *it != target) return ret;
        
        int start = it - nums.begin();
        ret[0] = start;
        
        int i = start;
        while(i < len && nums[i] == nums[start]) i++;
        
        i--;
        ret[1] = i;
        
        return ret;
    }
};