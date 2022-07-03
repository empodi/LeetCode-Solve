class Solution {    // Time:O(2n) = O(n)  Space: O(m) where m is the size of ASCII array
public:
    int lengthOfLongestSubstring(string s) {
        
        int ASCII[128] = { 0 };
        int maxLen = 0, left = 0, right = 0;
        
        for (auto c : s) {
            if (ASCII[c]) {
                while (ASCII[c]) {
                    ASCII[s[left++]]--;
                }
            }
            ASCII[c]++;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};