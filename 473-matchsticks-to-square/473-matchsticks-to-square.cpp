inline int MIN(int a, int b) { return a<b ? a:b; }
class Solution {
private:
    int edge;
    bool visited[20];
    bool solve(vector<int>& nums, int pos, int cur_len, int cnt) {
        if (cnt == 4) 
            return true;
        if (cur_len > edge) 
            return false;
        if (cur_len == edge) 
            return solve(nums, 0, 0, cnt + 1);
        
        for (int i = pos; i < nums.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            if (cur_len + nums[i] <= edge && solve(nums, i + 1, cur_len + nums[i], cnt)) 
                return true;
            visited[i] = false;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 || nums.size() < 4) return false;
        
        edge = sum / 4;
        for (int i = 0; i <= nums.size(); i++) visited[i] = false;
        //cout << edge;
        
        //sort(nums.begin(), nums.end(), greater<int>());
        return solve(nums, 0, 0, 0);
    }
};