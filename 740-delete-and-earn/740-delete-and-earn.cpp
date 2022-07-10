class Solution {
private:
    int idx_array[10001];
    vector<pair<int,int>> dp;
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memset(idx_array, -1, sizeof(idx_array));
        for (auto& n : nums) {
            if (idx_array[n] < 0) {
                idx_array[n] = dp.size();
                dp.push_back({n, n});
            }
            else dp[idx_array[n]].first += n;
        }
        /*
        for (auto& c : dp) {
            printf("(%d , %d) ", c.first, c.second);
        }
        */
        for (int i = 1; i < dp.size(); i++) {
            if (dp[i - 1].second + 1 == dp[i].second) {
                if (i >= 2) 
                    dp[i].first += dp[i - 2].first;
            }
            else dp[i].first += dp[i - 1].first;
            dp[i].first = max(dp[i].first, dp[i - 1].first);
        }
        return dp.back().first;
    }
};