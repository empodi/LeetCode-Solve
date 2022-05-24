class Solution {
private:
    int dest;
    vector<vector<int>> v;
    
    void solve(vector<vector<int>>& graph, vector<int> route, int last) {
        
        if (last == dest) {
            v.push_back(route);
            return;
        }
        for (int i = 0; i < graph[last].size(); i++) {
            route.push_back(graph[last][i]);
            solve(graph, route, graph[last][i]);
            route.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        dest = graph.size() - 1;
        vector<int> route(1,0);
        solve(graph, route, 0);
        return v;
    }
};