typedef pair<int, int> pii;
class Solution {
public:
    vector<pii> graph[101];
    int distance[101];
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        for (int i = 0; i < times.size(); i++) {    
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        for (int i = 1; i <= n; i++) {
            distance[i] = INT_MAX;
        }
        
        distance[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        pq.push({0, k});
        
        while (!pq.empty()) {
            
            int dist = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            
            if (distance[pos] < dist) continue;
            
            for (int i = 0; i < graph[pos].size(); i++) {
                
                int next = graph[pos][i].first;
                int nextCost = graph[pos][i].second + dist;
                
                if (nextCost < distance[next]) {
                    
                    distance[next] = nextCost;
                    pq.push({nextCost, next});
                }
            }
        }
        
        int answer = 0;
        
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) {
                answer = -1;
                break;
            }
            else answer = max(answer, distance[i]);
        }
        
        return answer;
    }
};