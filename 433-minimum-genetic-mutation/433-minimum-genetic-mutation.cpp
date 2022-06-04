class Solution {
private:
    char S[4] = {'A','C','G','T'};
    vector<string> myBank;
    
    bool check(const string& s) {
        for (auto elem : myBank) 
            if (elem == s)
                return true;
        return false;
    }
    
    int solve(const string& start,const string& end) {
        
        unordered_set<string> u;
        queue<pair<string, int>> q;
        q.push({start, 0});
        
        while (!q.empty()) {
            
            string str = q.front().first;
            int cnt = q.front().second;
            q.pop();
            
            if (str == end) 
                return cnt;
            
            auto it = u.find(str);
            if (it != u.end()) continue;
            u.insert(str);
            
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    char c = str[i];
                    str[i] = S[j];
        
                    if (check(str)) {
                        q.push({str, cnt + 1});
                    }
                    str[i] = c;
                }
            }
        }
        return -1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        myBank.assign(bank.begin(), bank.end());
        return solve(start, end);
    }
};