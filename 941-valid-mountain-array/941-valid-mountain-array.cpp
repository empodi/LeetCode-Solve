class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if (arr.size() < 3) return false;
        
        int idx = 1, len = arr.size();
        
        
        while (idx < len) {    
            if (arr[idx] == arr[idx - 1]) return false;
            if (arr[idx] < arr[idx - 1]) break;
            idx++;
        }
        
        if (idx == 1 || idx == len) return false;
        
        while (idx < len) {
            if (arr[idx] >= arr[idx - 1]) return false;   
            idx++;
        }
        
        return true;
    }
};