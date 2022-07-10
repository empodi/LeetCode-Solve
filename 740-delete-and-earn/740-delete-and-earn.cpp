inline int tri_max(int a, int b, int c) { a = a > b ? a:b; return a > c ? a:c;}
class Solution {
private:
    int idx_array[10001];
    vector<pair<int,int>> dp; // { sum of identical num, num }
    void set_dp (vector<int>& nums) {
        memset(idx_array, -1, sizeof(idx_array));
        for (auto& n : nums) {
            if (idx_array[n] < 0) {
                idx_array[n] = dp.size();
                dp.push_back({n, n});
            }
            else dp[idx_array[n]].first += n;
        }
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set_dp(nums);
        
        /* solve dp */
        for (int i = 1; i < dp.size(); i++) {
            if (dp[i - 1].second + 1 == dp[i].second) {
                    dp[i].first = tri_max(dp[i].first, dp[i - 1].first, (i > 1 ? dp[i].first + dp[i - 2].first : 0));
            }
            else dp[i].first += dp[i - 1].first;
        }
        return dp.back().first;
    }
};