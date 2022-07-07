class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int min_len = (nums[0] >= target) ? 1 : nums.size() + 1;
    
        for (int i = 1; i < nums.size() && min_len > 2; i++) {
            nums[i] = nums[i - 1] + nums[i];
            if (nums[i] < target) continue;
            while (left <= i) {
                if (nums[i] - nums[left] < target) {
                    min_len = min(min_len, i - left + 1);
                    break;
                }
                left++;
            }
        }
        return (min_len == nums.size() + 1) ? 0 : min_len;
    }
};