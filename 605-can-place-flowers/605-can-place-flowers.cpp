class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int cnt = 0, len = flowerbed.size();
        
        for (int i = 0; i < len; i++) {
            
            if (flowerbed[i] == 0) {
                
                if (len == 1) {
                    return true;
                }
                if (i == 0 && flowerbed[i + 1] == 0) {
                    cnt++;
                    flowerbed[i] = 1;
                }
                else if (i == len - 1 && flowerbed[i - 1] == 0) {
                    cnt++;
                    flowerbed[i] = 1;
                }
                else if (i > 0 && i < len - 1 && !flowerbed[i - 1] && !flowerbed[i + 1]) {
                    cnt++;
                    flowerbed[i] = 1;
                }
            }
            if (cnt >= n) return true;
        }
        
        return false;
    }
};