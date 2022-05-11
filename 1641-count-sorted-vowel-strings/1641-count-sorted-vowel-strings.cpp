class Solution {
public:
    int countVowelStrings(int n) {
    
        int endsWith[5] = { 1,1,1,1,1 };
        
        for (int i = 1; i < n; i++) {
            
            for (int idx = 1; idx < 5; idx++) {
                endsWith[idx] += endsWith[idx - 1];
            }
        }
        
        return endsWith[0] + endsWith[1] + endsWith[2] + endsWith[3] + endsWith[4];
    }
};