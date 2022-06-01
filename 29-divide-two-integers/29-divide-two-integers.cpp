class Solution {
    bool flag = true;
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
            flag = false;

        long a = dividend;
        long b = divisor;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        
        if (a < b) return 0;
        if (a == b) return flag ? 1 : -1;
        if (b == 1) return flag ? (a > INT_MAX ? a - 1 : a) : -a;
        
        long cnt = 1;
        long n = b;
        
        while (n <= a) {
            n = n << 1;
            cnt = cnt << 1;
        }
        
        n = n >> 1;
        cnt = cnt >> 1;
        
        while (n <= a) {
            n += b;
            cnt++;
        }
        
        return flag ? cnt - 1 : -(cnt - 1);
    }
};