class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int len = digits.size(), div = 0;
        
        for (int i = len - 1; i >= 0; i--) {
            
            digits[i]++;
            
            div = digits[i] / 10;
            
            if (!div) return digits;
            else digits[i] = 0;
        } 
        
        if (div) digits.insert(digits.begin(), 1); 
        return digits;
    }
};