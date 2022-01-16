class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max = 0, i = 1, len = prices.size();
        int curMin, curMax;
        
        while (i < len && prices[i - 1] >= prices[i]) i++;
        
        if (i == len) return max;
        
        curMin = prices[i - 1]; curMax = prices[i];
        max = curMax - curMin;
        
        for (; i < len; i++) {
            
            if (prices[i] < curMin) {
                curMin = prices[i];
                curMax = curMin;
                continue;
            }
            if (prices[i] > curMax) {
                curMax = prices[i];
                if (curMax - curMin > max) max = curMax - curMin;
            }
        }
    
        return max;
    }
};