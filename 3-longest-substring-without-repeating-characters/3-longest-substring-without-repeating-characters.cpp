class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        bool ASC[128];
        memset(ASC, false, sizeof(ASC));
        
        int localLen = 0, maxLen = 0, prevIdx = 0;
        
        for (int i = 0; i < s.length(); i++) {
            
            char c = s[i];
            
            if (ASC[c] == true) {
                localLen = 1;
                memset(ASC, false, sizeof(ASC));
                
                prevIdx++;
                ASC[s[prevIdx]] = true;
                i = prevIdx;
            }
            else {
                localLen++;
                maxLen = maxLen > localLen ? maxLen : localLen;
                ASC[c] = true;
            }
        }
        
        return maxLen;
    }
};