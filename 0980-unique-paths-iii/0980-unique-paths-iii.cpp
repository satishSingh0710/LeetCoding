class Solution {
public:
    vector<int> x = {0,0,-1,1}; 
    vector<int> y = {1,-1, 0,0};
    int solve(vector<vector<int>> &grid, int row, int col, int &eRow, int &eCol,int &m, int &n, int pathLength,int &empty){
        if (row<0||col<0||row>=m||col>=n|| grid[row][col] == -1) return 0; 
        if (row == eRow && col==eCol){
            if (pathLength-1 == empty){return 1;}
            return 0; 
        }
       
        // visited[row][col] = true; 
        grid[row][col] = -1;
        int ans = 0;
      
        for(int i = 0;i<4;i++){
            int nRow = row + x[i]; 
            int nCol = col + y[i]; 
            ans += solve(grid, nRow, nCol, eRow, eCol, m, n, pathLength + 1,empty);
        }
        // visited[row][col] = false;
        grid[row][col] = 0;
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
       
        // vector<vector<bool>> visited(m, vector<bool> (n, false)); 
        return solve(grid,sR,sC,eR,eC,m,n,0,countEmptySpaces);
    }
};