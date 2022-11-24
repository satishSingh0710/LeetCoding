class Solution {
public:
    bool found = false;
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int index, int row, int col){
        if (index == word.size()){found = true; return;}
        if (row<0 || col<0 || row>=board.size() || col>=board[0].size()) return;
        if (found == true) return;
        if (visited[row][col] == true) return;
        if (board[row][col]!=word[index]) return;
        visited[row][col] = true;

        dfs(board, visited, word, index+1, row, col+1);
        dfs(board, visited, word, index+1, row+1, col);
        dfs(board, visited, word, index+1, row-1, col);
        dfs(board, visited, word, index+1, row, col-1);
        visited[row][col] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0;i<n;i++){
            for  (int j = 0;j<m;j++){
                if (board[i][j] == word[0]){
                    dfs(board, visited, word,0, i,j);
                    if (found == true) return true;
                }
            }
        }
        return found;
    }
};