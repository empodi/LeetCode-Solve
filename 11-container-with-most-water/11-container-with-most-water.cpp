class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size() - 1, ans = 0;
        
        while (i < j) {
            
            int amount = (j - i) * min(height[i], height[j]);
            ans = amount > ans ? amount :ans;
            
            int left = height[i], right = height[j];
            
            if (left < right) {
                i++;
                while (i < height.size() && height[i] <= left) i++;
            }
            else {
                j--;
                while (j >= 0 && height[j] <= right) j--;
            }
        }
        
        return ans;
    }
};