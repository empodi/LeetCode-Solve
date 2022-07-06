class Solution {
private:
    int dp[40] = { 0, };
public:
    int fib(int n) {
        if (n < 2) return n;
        return (dp[n - 1] ? dp[n - 1] : (dp[n - 1] = fib(n - 1))) +
            (dp[n - 2] ? dp[n - 2] : (dp[n - 2] = fib(n - 2)));
    }
};