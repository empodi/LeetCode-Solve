class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, start = 0, end = 0;
        int ASC[128] = { 0, };
        
        while (end < s.length()) {
            if (ASC[s[end]] > 0) {
                while (start < end) {
                    ASC[s[start++]]--;
                    if (ASC[s[end]] == 0) break;
                }
            }
            maxLen = max(maxLen, end - start + 1);
            ASC[s[end]]++;
            end++;
        }
        return maxLen;
    }
};