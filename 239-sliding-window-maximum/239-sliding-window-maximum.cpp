class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        priority_queue<pair<int,int>> pq;
        
        for (int i = 0; i < nums.size(); i++) {
            pq.push({ nums[i], i });
            while (i >= k - 1 && !pq.empty() && pq.top().second <= i - k)
                pq.pop();
            if (i >= k - 1)
                v.push_back(pq.top().first);
        }
        return v;
    }
};