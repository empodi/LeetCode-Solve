class Solution {
private:
    int parent[210];
public:
    int Find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
    
        int len = isConnected.size();
        int cnt = 0;
        
        for (int i = 0; i <= len; i++) 
            parent[i] = i;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (i == j || !isConnected[i][j]) 
                    continue;
                
                int x = Find(i);
                int y = Find(j);
                isConnected[x][y] = isConnected[y][x] = 0;
                
                if (x != y) cnt++;
                parent[x] = y;
            }
        }
        
        return len - cnt;
    }
};