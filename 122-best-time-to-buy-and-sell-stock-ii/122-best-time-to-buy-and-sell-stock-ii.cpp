class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin = prices[0], ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] > prices[i]) {
                ret += (prices[i - 1] - curmin);
                curmin = prices[i];
            }
        }
        ret += max(prices.back() - curmin, 0);
        return ret;
    }
};