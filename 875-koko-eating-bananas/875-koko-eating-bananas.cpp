class Solution {
public:
    bool checkTime(vector<int>& piles, int h, int limit) {
        
        int hourCnt = 0;
        
        for (auto& n : piles) {
            
            hourCnt += n / h;
            if (n % h) hourCnt++;
            
            if (hourCnt > limit) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        if (h == piles.size()) return right;
        
        while (left <= right) {
            
            int mid = (left + right) / 2;
            
            if (checkTime(piles, mid, h)) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};