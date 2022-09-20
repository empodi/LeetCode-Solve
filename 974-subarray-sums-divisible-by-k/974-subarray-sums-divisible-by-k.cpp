class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {        
        int rem[10001] = {0,};
        int sum = 0, ret = 0;
        rem[0] = 1;
        for (auto& e : nums)
        {
            sum += e;
            int r = ((sum % k) + k) % k;
            ret += rem[r];
            rem[r]++;
        }
        return ret;
    }
};