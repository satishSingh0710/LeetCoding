class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(); 
        int l = 0, r = n*m - 1; 
        while(l<=r){
            int mid = l + (r-l)/2; 
            int row = mid/m, col = mid%m; 
            if(matrix[row][col] == target) return true; 
            if (matrix[row][col] < target){
                l = mid+1; 
            }else{
                r = mid-1; 
            }
        }
        return false;
    }
};