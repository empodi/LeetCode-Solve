class Solution {
private:
    int dp[40] = { 0, };
public:
    int tribonacci(int n) {
        if (n <= 0) return 0;
        if (n < 3) return 1;
        if (dp[n]) return dp[n];
        return dp[n] += (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
    }
};