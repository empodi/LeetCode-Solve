class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto& n:nums) {
            if (v.empty()) v.push_back(n);
            else {
                if (n > v.back()) v.push_back(n);
                else {
                    auto it = lower_bound(v.begin(), v.end(), n);
                    *it = n;
                }
            }
        }
        for (auto& c:v) cout << c << " "; cout << endl;
        return v.size();
    }
};