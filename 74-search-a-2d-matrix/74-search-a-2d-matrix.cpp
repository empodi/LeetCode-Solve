class Solution {
public:
    bool search(vector<vector<int>>& matrix, int target) {
        
        int height = matrix.size();
        int width = matrix[0].size();
        
        int i = 0, j = height * width - 1;
        
        while (i <= j) {
            
            int midRow = (i + j) / width;
            int midCol = (i + j) % width;
            
            if (matrix[midRow][midCol] == target) return true;
            
            if (target < matrix[midRow][midCol])
                j = midRow * width + midCol - 1;
            else
                i = midRow * width + midCol + 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        return search(matrix, target);
    }
};