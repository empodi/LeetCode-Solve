class Solution {
public:
    int arr[2501];
    
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 1) return 1;
        int idx = 0;
        arr[idx] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > arr[idx]) 
                arr[++idx] = nums[i];
            else {
                int pos = lower_bound(arr, arr + idx, nums[i]) -arr;
                arr[pos] = nums[i];
            }
        }
        
        return idx + 1;
    }
};