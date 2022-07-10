inline int MIN(int a, int b) { return (a < b ? a : b); }
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i < cost.size(); i++) {
            cost[i] += MIN(cost[i - 1], cost[i - 2]);
        }
        return MIN(cost.back(), cost[cost.size() - 2]);
    }
};