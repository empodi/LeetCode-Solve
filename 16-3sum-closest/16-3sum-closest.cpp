class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int diff = abs(ans - target);
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return sum;
                if (abs(sum - target) < diff) {
                    ans = sum; diff = abs(sum - target);
                }
                if (sum > target) right--;
                else left++;
            }
        }
        return ans;
    }
};