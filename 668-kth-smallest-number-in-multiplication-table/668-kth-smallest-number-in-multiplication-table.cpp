class Solution {
public:
    int count(const int& m, const int& n, int target) {
        int ret = 0;
        for (int i = 1; i <= m; i++) ret += min(n, target/i);
        return ret;
    }
    int findKthNumber(int m, int n, int k) {
        int s = 0, e = m * n;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (count(m, n, mid) < k) s = mid + 1;
            else e = mid - 1;
        }
        return s;
    }
};
