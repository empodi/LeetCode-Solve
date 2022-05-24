class Solution {
private:
    int len;
    bool visited[1001];
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        queue<int> q;
        int cnt = 0;
        len = rooms.size();
        
        memset(visited, false, sizeof(visited));
        
        q.push(0);
        
        while (!q.empty() && cnt < len) {
            int cur = q.front();
            q.pop();

            if (visited[cur]) continue;
            visited[cur] = true;
            cnt++;
            
            for (int i = 0; i < rooms[cur].size(); i++) {
                int next = rooms[cur][i];
                if (visited[next]) continue;
                q.push(next);
            }
        }
        
        return cnt == len;
    }
};