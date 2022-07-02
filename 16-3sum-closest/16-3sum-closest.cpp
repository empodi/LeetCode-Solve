class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, ans = 0;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) return target;
                int d = abs(sum - target);
                if (d < diff) {
                    ans = sum;
                    diff = d;
                }
                if (sum > target) right--;
                else left++;
            }
        }
        return ans;
    }
};