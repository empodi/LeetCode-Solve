inline int MAX(int a,int b){return a > b ? a:b;}
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int posLen=0, negLen=0, answer=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                posLen++;
                negLen = negLen == 0 ? 0 : negLen + 1;
            }
            else if (nums[i] < 0) {
                int prev_neg = negLen;
                negLen = posLen == 0 ? 1 : posLen + 1;
                posLen = prev_neg == 0 ? 0 : prev_neg + 1;
            }
            else {
                posLen = negLen = 0;
            }
            answer = MAX(answer, posLen);
        }
        return answer;
    }
};