class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int len = nums.size();
        
        for (int i = 0; i < len - 3; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0 && nums[i] > target) break;
            for (int j = i + 1; j < len - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int twoSum = nums[i] + nums[j];
                if (twoSum > 0 && twoSum > target) break;
                
                int left = j + 1, right = len - 1;
                while (left < right) {
                    long sum = (long)twoSum + nums[left] + nums[right];
                    if (sum == target) {
                        ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++; right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (sum > target) 
                        right--;
                    else 
                        left++;
                }   
            }
        }
        return ret;
    }
};