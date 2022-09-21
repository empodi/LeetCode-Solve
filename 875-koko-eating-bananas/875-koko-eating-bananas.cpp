class Solution {
public:
    long long check(const vector<int>& piles, const int& m) {
        long long ret = 0;
        for (auto& p : piles) ret += (p % m == 0 ? p / m : p / m + 1);
        return ret;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = 1e9;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (check(piles, mid) <= h) e = mid - 1;
            else s = mid + 1;
        }
        return s;
    }
};