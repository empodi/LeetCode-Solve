class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        vector<int> ret;
        
        int m = 1;
        for (int i = 0; i < nums.size(); i++) 
        {
            m *= nums[i];
            left[i] = m;
        }
        m = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            m *= nums[i];
            right[i] = m;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0) ret.push_back(right[i + 1]);
            else if (i == nums.size() - 1) ret.push_back(left[i - 1]);
            else ret.push_back(left[i - 1] * right[i + 1]);
        }
        return ret;
    }
};