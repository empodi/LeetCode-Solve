class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int cur_max = INT_MIN;
        multiset<int> pq;
        pq.insert(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += *(pq.rbegin());
            if (i >= k) {
                auto it = pq.find(nums[i - k]);
                pq.erase(it);
            }
            pq.insert(nums[i]);
        }
        //for (auto& c : nums)
            //cout << c << " ";
        //cout << endl;
        return nums.back();
    }
};