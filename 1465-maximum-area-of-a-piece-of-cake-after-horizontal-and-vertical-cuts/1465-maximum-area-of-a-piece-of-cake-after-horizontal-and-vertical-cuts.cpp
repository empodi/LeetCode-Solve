#define MOD 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHeight = 0, maxWidth = 0;
        
        for (int i = 0; i < horizontalCuts.size(); i++) {
            if (i == 0) {
                maxHeight = max(maxHeight, horizontalCuts[i]);
            }
            else {
                maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
            }
            if (i == horizontalCuts.size() - 1) {
                maxHeight = max(maxHeight, h - horizontalCuts[i]);
            }
        }
        for (int i = 0; i < verticalCuts.size(); i++) {
            if (i == 0) {
                maxWidth = max(maxWidth, verticalCuts[i]);
            }
            else {
                maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
            }
            if (i == verticalCuts.size() - 1) {
                maxWidth = max(maxWidth, w - verticalCuts[i]);
            }
        }

        return ((long)maxWidth * maxHeight) % MOD;
    }
};