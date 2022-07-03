class Solution {
private:
    int binarySearch(vector<int>& nums, int& target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        int idx = binarySearch(nums, target);
        if (idx < 0) return {-1,-1};
        int lo = idx, hi = idx;
        while (lo >= 0 && nums[lo] == nums[idx]) lo--;
        while (hi < nums.size() && nums[hi] == nums[idx]) hi++;
        return {lo + 1, hi - 1};
    }
};
