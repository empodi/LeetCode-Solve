class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if (nums.size() < 2) return 1;
        
        int ans = 1, idx = 0;
        bool flag;
        
        while (idx < nums.size() - 1 && nums[idx] == nums[idx + 1]) idx++;
        
        if (idx + 1 < nums.size()) {
            flag = (nums[idx] < nums[idx + 1]) ? true : false;
            ans++;
        }
        
        for (int i = idx; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) continue;
            if (flag) {
                if (nums[i] < nums[i + 1]) continue;
                ans++; flag = false;
            }
            else {
                if (nums[i]> nums[i + 1]) continue;
                ans++; flag = true;
            }
        }
        
        return ans;
    }
};