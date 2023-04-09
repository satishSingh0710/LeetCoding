class Solution {
public:
    queue<pair<pair<int,int>, int>> q;
    void bfs(vector<vector<int>> &mat, vector<vector<int>> &vis, vector<vector<int>> &res){
        while(!q.empty()){
            auto val = q.front();
            q.pop();
            int row = val.first.first, col = val.first.second;
           // cout<<row<<" "<<col<<endl;
          res[row][col] = val.second;
            int dist = res[row][col];
              int a[] = {0,1,0,-1};
            int b[] = {1,0,-1,0};
            for (int i = 0;i<4;i++){
                int newRow = row + a[i], newCol = col + b[i];
                if (newRow < 0 || newCol < 0 || newRow>=mat.size()||newCol>=mat[0].size()) continue;
                if (vis[newRow][newCol] == 1) continue;
                q.push({{newRow, newCol},dist + 1});
                vis[newRow][newCol] = 1;
            }
        }    
    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> fRes(m, vector<int>(n, 0)), visited(m, vector<int>(n, -1));
        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                if (mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i,j}, 0});
                }
            }
        }
        bfs(mat, visited, fRes);
        return fRes;
    }
};