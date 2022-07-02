class Solution {
private:
    int binarysearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1;
        
        if (nums[left] <= nums[right]) 
            return binarysearch(nums, left, right, target);
        
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[left] > nums[mid]) right = mid;
            else left = mid;
        }
        //cout << nums[left] << " " << nums[right];

        if (target >= nums[0]) return binarysearch(nums, 0, left, target);
        else return binarysearch(nums, right, nums.size() - 1, target);
    }
};