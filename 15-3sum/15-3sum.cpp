class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    left++; 
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ret;
    }
};