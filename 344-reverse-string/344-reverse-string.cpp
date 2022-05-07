class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int sLen = s.size();
        int halfLen = sLen / 2;
        
        for (int i = 0; i < halfLen; i++) {
            
            char tmp = s[i];
            s[i] = s[sLen - 1 - i];
            s[sLen - 1 - i] = tmp;
        }
    }
};