class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                
                if (pq.empty()) {
                    pq.push(matrix[i][j]);
                    continue;
                }
                
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                }
                else if (pq.top() > matrix[i][j]) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        
        return pq.top();
    }
};

