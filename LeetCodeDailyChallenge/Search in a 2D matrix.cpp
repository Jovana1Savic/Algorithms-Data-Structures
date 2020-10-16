// Problem statement: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int left = 0, right = n * m - 1;
        
        while (left <= right){
            
            int mid = left + (right - left) / 2;
            
            int i = mid / m;
            int j = mid % m;
            
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
