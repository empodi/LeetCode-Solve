class Solution {
public:
    int jump(vector<int>& nums) {
        
        int len = nums.size();
        int cnt = 0, localMax = 0, globalMax = 0;
        
        for (int i = 0; i < len - 1; i++) {
            globalMax = max(globalMax, i + nums[i]);
            
            if (i == localMax) {
                cnt++;
                localMax = globalMax;
            }
        }
        
        return cnt;
    }
};