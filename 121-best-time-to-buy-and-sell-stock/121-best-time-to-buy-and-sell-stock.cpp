class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() <= 1) return 0;
        
        int max = 0, ans = 0, min = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            
            if (prices[i] < min) {
                min = prices[i];
                max = min;
                continue;
            }
            if (prices[i] > max) {
                max = prices[i];
                if (max - min > ans) ans = max - min;
            }
        }
    
        return ans;
    }
};