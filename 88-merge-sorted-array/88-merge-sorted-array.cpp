class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if (n == 0) return;
        
        int j = nums1.size() - m, k = 0, idx = 0;
        
        for (int i = m - 1; i >= 0; i--) 
            nums1[i + j] = nums1[i];
        
        while (j > 0 && j < nums1.size() && k < n) {
            if (nums1[j] < nums2[k]) 
                nums1[idx++] = nums1[j++];
            else
                nums1[idx++] = nums2[k++];
        }
        
        while (j > 0 && j < nums1.size()) 
            nums1[idx++] = nums1[j++];
        while (k < n) 
            nums1[idx++] = nums2[k++];
    }
};