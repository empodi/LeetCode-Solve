class Solution {
private:
    vector<int> graph[30];
    bool solve(string& w, int prevIdx, int curIdx, int targetLen) {
        if (curIdx == targetLen) return true;
        bool ret = false;
        for (int i = 0; i < graph[w[curIdx] - 'a'].size(); i++) {
            if (graph[w[curIdx] - 'a'][i] > prevIdx) {
                ret |= solve(w, graph[w[curIdx] - 'a'][i], curIdx + 1, targetLen);
                break;
            }
        }
        return ret;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        for (int i = 0; i < s.length(); i++) {
            graph[s[i] - 'a'].push_back(i);
        }
        
        int cnt = 0;
        for (auto& word : words) {
            if (solve(word, -1, 0, word.length())) {
                cnt++;
            }
        }
        return cnt;
    }
};