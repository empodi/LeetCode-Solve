class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> mp;
        bool isOne = false;
        int ans = 0;
        
        for (auto& c : s) mp[c]++;
        
        for (auto x : mp) {
            
            if (!isOne && x.second == 1) isOne = true;
            if (x.second % 2 == 1) {
                ans += x.second - 1;
                isOne = true;
            }
            else ans += x.second;
        }
        
        if (isOne) ans++;
        
        return ans;
    }
};