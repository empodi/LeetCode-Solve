inline int Max(int a, int b, int c) { a = a > b ? a:b; return a > c ? a:c; }
inline int Min(int a, int b, int c) { a = a < b ? a:b; return a < c ? a:c; }
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int answer = nums[0];
        
        vector<int> maxDP(nums.size()), minDP(nums.size());
        maxDP[0] = minDP[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                maxDP[i] = minDP[i] = 0;
            }
            else {
                maxDP[i] = Max(nums[i], nums[i] * maxDP[i - 1], nums[i] * minDP[i - 1]);
                minDP[i] = Min(nums[i], nums[i] * maxDP[i - 1], nums[i] * minDP[i - 1]);
            }
            answer = answer > maxDP[i] ? answer : maxDP[i];
        }
        //for (auto& c : maxDP) printf("%4d", c); cout << endl;
        //for (auto& c : minDP) printf("%4d", c); cout << endl;
        return answer;
    }
};