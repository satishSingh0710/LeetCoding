class Solution {
private: 
    int endRow, endCol, result = 0, empty = 0;
    int rows, cols;
public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int count){
       
        if (row == endRow && col== endCol){ 
            count--;
            if (count == empty)
            { result++;}
            return;
        }
        if (row<0 || col<0 || row>=rows || col>=cols){
          return;
        }
        if (grid[row][col] == -1) return;
        if (visited[row][col] == true) return;
        
        
        visited[row][col] = true;
        
        dfs(grid, visited, row+1, col, count+1);
        dfs(grid, visited, row, col+1, count+1);
        dfs(grid, visited, row-1, col, count+1);
        dfs(grid, visited, row,col-1, count+1);
        visited[row][col] = false;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
       
       int n = grid.size(), m = grid[0].size(), startRow, startCol;
        rows = n, cols = m;
       vector<vector<bool>> visited(n, vector<bool>(m, false));
       
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (grid[i][j] == 0){
                   empty++;
                }
                if (grid[i][j] == 1){
                    startRow = i; startCol = j;
                }
                if (grid[i][j] == 2){
                    endRow = i; endCol = j;
                }
            }
        }

        dfs(grid, visited, startRow, startCol,0);
        return result;
      
    }
};