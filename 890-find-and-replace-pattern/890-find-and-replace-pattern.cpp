class Solution {
private:
    bool check(const string& word, const string& pat) {
        unordered_map<char,char> wm, pm;
        
        for (int i = 0; i < word.size(); i++) {
            if (wm[word[i]] == NULL && pm[pat[i]] == NULL) {
                wm[word[i]] = pat[i];
                pm[pat[i]] = word[i];
                continue;
            }
            if (wm[word[i]] != pat[i] || pm[pat[i]] != word[i]) return false;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> answer;
        
        for (string &word : words) {
            if (check(word, pattern)) 
                answer.emplace_back(word);
        }
        return answer;
    }
};