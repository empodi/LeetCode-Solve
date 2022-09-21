class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> A(prices.size(), 0); // hold stock, can sell
        vector<int> B(prices.size(), 0); // just sold stock, only can rest
        vector<int> C(prices.size(), 0); // rest, can buy stock
        
        A[0] = -prices[0];
        B[0] = INT_MIN;
        
        for (int i = 1; i < prices.size(); i++) {
            A[i] = max(A[i - 1], C[i - 1] - prices[i]);
            B[i] = A[i - 1] + prices[i];
            C[i] = max(C[i - 1], B[i - 1]);
        }
        return max(B.back(), C.back());
    }
};