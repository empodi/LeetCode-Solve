class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     
        int idx = 0, len = nums.size();
        
        for (int i = 0; i < len; ) {
            
            int val = nums[i];
            bool flag = false;
            
            nums[idx++] = val;
            if (i + 1 < len && nums[i + 1] == val)
                flag = true;
            i++;
            while (i < len && nums[i] == val) i++;
            
            if (flag) nums[idx++] = val;
            
        }
        
        return idx;
    }
};