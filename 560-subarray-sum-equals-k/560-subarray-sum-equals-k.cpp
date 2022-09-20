class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int sum = 0, ret = 0;
        um[sum]++;
        
        for (auto& e: nums)
        {
            sum += e;
            if (um.find(sum - k) != um.end()) ret += um[sum - k];
            um[sum]++;
        }
        return ret;
    }
};