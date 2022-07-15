inline int MAX(int a,int b){return a>b ? a:b;}
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int answer = 0;
        int curMax = values[0];
        for (int i = 1; i < values.size(); i++) {
            curMax = MAX(curMax - 1, values[i - 1] - 1);
            answer = MAX(curMax + values[i], answer);
        }
        return answer;
    }
};