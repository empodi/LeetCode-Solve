class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin = prices[0], answer = 0;
        for (int i = 1; i < prices.size(); i++) {
            answer = max(answer, prices[i] - curmin);
            curmin = min(curmin, prices[i]);
        }
        return answer;
    }
};