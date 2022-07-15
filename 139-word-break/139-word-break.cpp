class Solution {
private:
    vector<string> dict[30];
    int dp[301] = { 0, };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) {
            dict[word[0] - 'a'].push_back(word);
        }
        int idx = 0;
        while (idx < s.length()) {
            for (string c: dict[s[idx] - 'a']) {
                if (c == s.substr(idx, c.length())) 
                    dp[idx + c.length() - 1] = 1;
            }
            while (idx < s.length() && dp[idx] != 1) idx++;
            idx++;
        }
        return dp[s.length() - 1];
    }
};