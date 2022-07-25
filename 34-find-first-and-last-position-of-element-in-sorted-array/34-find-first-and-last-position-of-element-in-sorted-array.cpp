class Solution {
private:
    int binary_search(vector<int>& nums, int target, bool flag) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = mid;
                flag ? right = mid - 1 : left = mid + 1;
            }
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return result;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binary_search(nums, target, true), binary_search(nums, target, false)};
    }
};