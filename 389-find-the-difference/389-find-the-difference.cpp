class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int table[26] = { 0, };
        
        char ans = ' ';
        
        for (auto& c : s) {
            table[c - 'a']++;
        }
        
        for (auto& c : t) {
            if (table[c - 'a'] == 0) {
                ans = c;
                break;
            }
            table[c - 'a']--;
        }
        
        return ans;
    }
};