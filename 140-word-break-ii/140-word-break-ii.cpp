class Solution {
private:
    vector<string> answer;
    vector<string> dict[30];
    void solve(string& s, string& cur, int startIdx) {
        if (startIdx == s.length()) {
            cur.pop_back();
            answer.push_back(cur);
            return;
        }
        string origin = cur;
        for (string w : dict[s[startIdx] - 'a']) {
            if (startIdx + w.length() <= s.length() && w == s.substr(startIdx, w.length())) {
                cur += (w + " ");
                solve(s, cur, startIdx + w.length());
                cur = origin;
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string& word : wordDict) {
            dict[word[0] - 'a'].push_back(word);
        }
        string cur = "";
        solve(s, cur, 0);
        return answer;
    }
};