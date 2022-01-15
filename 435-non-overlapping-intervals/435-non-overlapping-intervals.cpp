class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        
        sort(v.begin(), v.end(), [] (vector<int>& v1, vector<int>& v2){return v1[1] < v2[1];});
        
        int len = 1, endTime = v[0][1];
        
        for (int i = 1; i < v.size(); i++) {
            if (v[i][0] >= endTime) {
                len++;
                endTime = v[i][1];
            }
        }
        
        return v.size() - len;
    }
};