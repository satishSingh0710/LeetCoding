class Solution {
public:
//     void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col){
//         if (row<0||col<0||row>=board.size() || col>=board[0].size()||visited[row][col] || board[row][col]=='X') return;
//         board[row][col] = '*';
//         visited[row][col] = true;
//         dfs(board, visited, row+1, col);
//         dfs(board, visited, row, col+1);
//         dfs(board, visited, row-1,col);
//         dfs(board, visited, row, col-1);

//     }
    void bfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col){
        if (visited[row][col] == true) return;
        queue<pair<int,int>>   q;
        visited[row][col] = true;
        q.push({row, col});
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            // cout<<r<<" "<<c<<endl;
            q.pop();
            board[r][c] = '*';
            int a[] = {0,0,1,-1};
            int b[] = {1,-1,0,0};
            for (int i = 0;i<4;i++){
                int nRow = r + a[i];
                int nCol = c + b[i];
                if (nRow >= 0 && nCol>=0 && nRow<board.size() && nCol < board[0].size() && visited[nRow][nCol] == false && board[nRow][nCol] == 'O'){
                    q.push({nRow, nCol});
                    visited[nRow][nCol] = 1;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0;i<m;i++){
            if (board[i][0] == 'O'){
                bfs(board, vis, i, 0);
            }
            if (board[i][n-1] == 'O'){
                bfs(board, vis, i, n-1);
            }
        }
        
        for (int i = 0;i<n;i++){
            if (board[0][i] == 'O'){
                bfs(board, vis, 0, i);
            }
            if (board[m-1][i] == 'O'){
                bfs(board, vis, m-1, i);
            }
        }
        
        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                if (board[i][j] == '*'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
        
        // return board;
    }
};