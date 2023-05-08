class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1; 
        while(i<matrix.size() && j>=0){
            int currNum = matrix[i][j]; 
            if (currNum == target) return true; 
            if (currNum < target){i++;}
            else if (currNum > target){j--;}
        }
        return false;
    }
};