#define MOD 1000000007
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {       
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHeight = max(horizontalCuts[0], h - horizontalCuts.back()); 
        int maxWidth = max(verticalCuts[0], w - verticalCuts.back());
        
        for (int i = 1; i < horizontalCuts.size(); i++) {
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); i++) {
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return ((long)maxWidth * maxHeight) % MOD;
    }
};