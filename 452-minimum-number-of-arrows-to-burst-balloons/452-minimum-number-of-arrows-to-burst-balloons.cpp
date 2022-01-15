class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if (points.size() == 1) return 1;
        
        sort(points.begin(), points.end());
        
        int cnt = 1, len = points.size();
        int start = points[0][0], end = points[0][1];
        
        for (int i = 1; i < len; i++) {
            if (points[i][0] > end) {
                cnt++;
                start = points[i][0];
                end = points[i][1];
            } 
            else {
                start = start > points[i][0] ? start : points[i][0];
                end = end < points[i][1] ? end : points[i][1];
            }
        }
        
        return cnt;
    }
};