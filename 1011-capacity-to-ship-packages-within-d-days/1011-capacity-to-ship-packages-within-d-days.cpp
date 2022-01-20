class Solution {
public:
    bool check(vector<int>& weights, int cap, int days) {
        
        int sum = 0, cnt = 1;
        
        for (int i = 0; i < weights.size(); i) {
            
            if (sum + weights[i] <= cap) {
                sum += weights[i++];
            }
            else {
                cnt++;
                sum = 0;
            }
            
            if (cnt > days) return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int total = 0;
        
        for (auto& elem : weights) 
            total += elem;
        
        if (days == 1) return total;
        
        int left = *max_element(weights.begin(), weights.end());
        int right = total;
        
        cout << left << " " << right;
        
        while (left <= right) {
            
            int mid = (left + right) / 2;
            
            if (check(weights, mid, days)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};