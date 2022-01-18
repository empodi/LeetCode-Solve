class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int len = nums.size(), idx = 0;
        
        for (int i = 0 ; i < len; ) {
            int val = nums[i];
            nums[idx++] = val;
            i++;
            
            while (i < len && nums[i] == val) i++;
        }
        
        return idx;
    }
};