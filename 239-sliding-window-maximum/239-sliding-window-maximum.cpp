class Solution {
public:
    int numsLen;
    int counter[20002] = { 0 };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        numsLen = nums.size();
        priority_queue<int> pq;
        
        vector<int> answer;
        int left = 0, right = k - 1;
        
        while (right < numsLen) {
            
            if (left == 0) {
                
                for (int i = left; i <= right; i++) {
                    counter[nums[i] + 10000]++;
                    pq.push(nums[i]);
                }
            }
            else {
                
                counter[nums[left - 1] + 10000]--;
                counter[nums[right] + 10000]++;
                pq.push(nums[right]);
            }
            
            while (!pq.empty() && counter[pq.top() + 10000] == 0) {
                pq.pop();
            }
            
            answer.push_back(pq.top());
            left++;
            right++;
        }
        
        return answer;
    }
};