class Solution {
private:
    int alpha[26];
    int alpha_num = 0;
    bool check(vector<int>& counts) {
        for (int i = 0 ; i < 26; i++) {
            if (counts[i] < alpha[i])
                return false;
        }
        return true;
    }
    vector<string> solve(vector<string>& words) {
        vector<string> ret;
        
        for (string& word: words) {
            vector<int> counts(26, 0);
            
            for (char& c: word) {
                if (alpha[c - 'a']) {
                    counts[c - 'a']++;
                }
            }
            if (check(counts)) ret.push_back(word);
        }
        
        return ret;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        memset(alpha, 0, sizeof(alpha));
        
        for (string& str : words2) {
            vector<int> tmp(26, 0);
            for (char& c : str) 
                tmp[c - 'a']++;
            for (int i = 0; i < 26; i++)
                alpha[i] = max(alpha[i], tmp[i]);
        }
        
        return solve(words1);
    }
};