class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[dq.front()];
            
            while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            dq.push_back(i);
        }
        return nums.back();
    }
};