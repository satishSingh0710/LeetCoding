class Solution {
public:
    int solve(vector<vector<int>> &grid, int row, int col, int &eRow, int &eCol,int &m, int &n, int pathLength,int &empty,vector<vector<bool>> &visited, vector<vector<int>> &dp){
        if (row<0||col<0||row>=m||col>=n||visited[row][col] || grid[row][col] == -1) return 0; 
        if (row == eRow && col==eCol){
            if (pathLength-1 == empty){return 1;}
            return 0; 
        }
        // if (dp[row][col]!=-1) return dp[row][col];
        visited[row][col] = true; 
        int ans = 0;
        ans = ans + solve(grid, row+1, col, eRow, eCol, m,n,pathLength+1,empty, visited, dp); 
        ans = ans+ solve(grid, row-1, col, eRow, eCol, m, n, pathLength +1, empty, visited,dp); 
        ans += solve(grid, row, col+1, eRow, eCol, m, n, pathLength+1, empty, visited, dp); 
        ans += solve(grid, row, col-1, eRow, eCol, m, n, pathLength +1, empty, visited, dp);
        visited[row][col] = false;
        return  ans; 
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int countEmptySpaces = 0;
        int m=grid.size(), n = grid[0].size();
        int sR =0, sC= 0, eR=0, eC=0;
        for (int i = 0;i<grid.size();i++){
            for (int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 0){countEmptySpaces++;}
                else if (grid[i][j] == 1){sR = i; sC = j;}
                else if (grid[i][j] == 2){eR  = i; eC = j;}
            }
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool> (n, false)); 
        return solve(grid,sR,sC,eR,eC,m,n,0,countEmptySpaces,visited,dp);
    }
};