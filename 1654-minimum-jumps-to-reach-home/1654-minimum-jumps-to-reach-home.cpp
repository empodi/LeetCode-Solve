typedef pair<int,int> pii; // cur, prev <= positive when prev jump was heading forward
class Solution {
private:
    int a;
    int b;
    int x;
    bool visited[20001];
    int solve() {
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while (q.size() > 0) {
            int cur = q.front().first;
            int jmp = q.front().second;
            q.pop();
            
            if (cur == x) {
                return abs(jmp);
            }
            if (cur > 20000) continue;
            if (visited[cur]) continue;
            visited[cur] = true;
            
            if (jmp >= 0 && cur - b > 0) 
                q.push({cur - b, -(jmp + 1)});
            
            q.push({cur + a, abs(jmp) + 1});
        }
        return -1;
    }
public:
    int minimumJumps(vector<int>& forbidden, int _a, int _b, int _x) {
        a = _a;
        b = _b;
        x = _x;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < forbidden.size(); i++)
            visited[forbidden[i]] = true;
        
        return solve();
    }
};