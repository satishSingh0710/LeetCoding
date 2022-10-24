class Solution {
public:
    void findOut(vector<vector<int>> &board, int &dead, int &alive, int row, int col){
        int n= board.size(), m = board[0].size();
        for (int i = -1;i<=1;i++){
            for (int j = -1; j<=1;j++){
                int nrow = row + i, ncol = col+j;
                if (nrow>=n || nrow<0 ||  ncol>= m || ncol<0) continue;
                if (nrow == row && ncol == col) continue;
                if (board[nrow][ncol] == 1) alive++;
                if (board[nrow][ncol]==0)dead++;
            }
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> grid= board;
        int n = board.size(), m = board[0].size();
        for (int i = 0;i<n;i++){
            
            for (int j = 0;j<m;j++){
                  int dead = 0, alive = 0;
                  findOut(grid, dead, alive, i,j);
                  // cout<<dead<<" "<<alive<<endl;
                   if (grid[i][j] == 1){
                       if (alive<2){board[i][j] = 0;}
                       else if (alive == 2 || alive == 3) board[i][j] = 1;
                       else if (alive>3) board[i][j] = 0;
                   } else{
                       if (alive == 3){
                           board[i][j] = 1;
                       }
                   }
            }
        }
        
    }
};