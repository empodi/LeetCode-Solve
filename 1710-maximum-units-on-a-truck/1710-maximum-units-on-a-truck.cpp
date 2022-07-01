bool compare(vector<int>& a, vector<int>& b) {
        return a[1] >= b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int i = 0, answer = 0;
        while (i < boxTypes.size() && truckSize) {
            
            int amount = min(truckSize, boxTypes[i][0]);
            answer += amount * boxTypes[i][1];
            
            truckSize -= amount;
            i++;
        }
        
        return answer;
    }
};