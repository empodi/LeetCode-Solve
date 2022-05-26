class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        if (start < 0 || start >= arr.size() || arr[start] < 0)
            return false;
        if (arr[start] == 0)
            return true;
        
        int dist = arr[start];
        arr[start] = -1;
        
        if (canReach(arr, start - dist) || canReach(arr, start + dist))
            return true;
        return false;
    }
};