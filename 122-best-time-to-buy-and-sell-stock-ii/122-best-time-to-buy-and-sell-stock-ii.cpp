class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int globalMin = prices[0];
        int answer = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] > globalMin) {
                answer += prices[i] - globalMin;
                globalMin = prices[i];
            }
            else globalMin = min(globalMin, prices[i]);
        }
        return answer;
    }
};