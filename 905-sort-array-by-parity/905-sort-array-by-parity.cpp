bool comp(int x, int y) {
        
        int xmod = x % 2;
        int ymod = y % 2;
        
        if (!xmod && ymod) return true;
        return false;
    }

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), comp);
        
        return nums;
    }
};