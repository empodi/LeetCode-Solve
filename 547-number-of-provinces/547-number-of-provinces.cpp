class Solution {
public:
    //bool visited[201];
    void check(vector<vector<int>>& A, int city) {
        for (int i = 0; i < A[city].size(); i++) {
            if (!A[city][i]) continue;
            A[city][i] = 0;
            check(A, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    
        int len = isConnected.size();
        int answer = 0;
        
        for (int i = 0; i < len; i++) {
            if (isConnected[i][i]) {
                check(isConnected, i);
                answer++;
            }
        }
        return answer;
    }
};