class Solution {
public:
    int longestPalindrome(string s) {
        
        int len = 0, ans = 0;
        vector<int> v(256, 0);
        
        for (auto& c : s) v[c]++;
        
        for (auto& elem : v) if (elem) len++;
        
        for (int i = 0; i < len; i++) {
            int pos = max_element(v.begin(), v.end()) - v.begin();
            if (v[pos] % 2 == 1 && v[pos] > 1) {
                ans += v[pos] - 1;
                v[pos] = 1;
            }
            else if (v[pos] % 2 == 0) {
                ans += v[pos];
                v[pos] = 0;
            }
        }
        
        for (auto& elem : v) 
            if (elem) {
                ans++;
                break;
            }
        
        return ans;
    }
};