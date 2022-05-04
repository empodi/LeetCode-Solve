class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int len = nums.size();
        int zeroCnt = 0;
        
        for (int i = len - 1; i >= 0; i--) {
            
            if (nums[i]) continue;
            
            for (int j = i; j < len - 1 - zeroCnt; j++) {
                swap(nums[j], nums[j + 1]);
            }
            
            zeroCnt++;
        }
    }
};