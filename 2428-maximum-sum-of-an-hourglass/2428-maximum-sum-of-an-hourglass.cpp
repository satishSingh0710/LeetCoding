class Solution {
public:
         int maxxi = INT_MIN;
         vector<int> x = {1,-1};
         vector<int> y = {0,-1,+1};
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        for (int i = 0;i<m-2;i++){
            for (int j = 0;j<n-2;j++){
               int sum = findSum(grid,i+1,j+1);
                maxxi = max(maxxi,sum);
            }
        }
        return maxxi;
    }
    
    int findSum(vector<vector<int>> &grid, int row,int col){
        int sum = grid[row][col];
         
        for (int i = 0;i<2;i++){
            for (int j = 0;j<3;j++){
                int nrow,ncol;
                nrow = row + x[i]; ncol = col + y[j];
                sum += grid[nrow][ncol];
            }
        }
        
        return sum;
    }
};