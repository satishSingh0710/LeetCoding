class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col){
        if (row<0||col<0||row>=board.size() || col>=board[0].size()||visited[row][col] || board[row][col]=='X') return;
        board[row][col] = '*';
        visited[row][col] = true;
        dfs(board, visited, row+1, col);
        dfs(board, visited, row, col+1);
        dfs(board, visited, row-1,col);
        dfs(board, visited, row, col-1);

    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0;i<m;i++){
            if (board[i][0] == 'O'){
                dfs(board, vis, i, 0);
            }
            if (board[i][n-1] == 'O'){
                dfs(board, vis, i, n-1);
            }
        }
        
        for (int i = 0;i<n;i++){
            if (board[0][i] == 'O'){
                dfs(board, vis, 0, i);
            }
            if (board[m-1][i] == 'O'){
                dfs(board, vis, m-1, i);
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