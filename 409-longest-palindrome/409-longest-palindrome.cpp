class Solution {
public:
    int longestPalindrome(string s) {
        
        int len = 0, ans = 0;
        bool isOne = false;
        vector<int> v(256, 0);
        
        for (auto& c : s) v[c]++;
        
        for (auto& elem : v) {
            if (elem) len++;
            if (elem == 1) isOne = true;
        }
        
        for (int i = 0; i < len; i++) {
            int pos = max_element(v.begin(), v.end()) - v.begin();
            if (v[pos] % 2 == 1 && v[pos] > 1) {
                ans += v[pos] - 1;
                v[pos] = 1;
                isOne = true;
            }
            else if (v[pos] % 2 == 0) {
                ans += v[pos];
                v[pos] = 0;
            }
        }
        
        if (isOne) ans++;
        
        return ans;
    }
};