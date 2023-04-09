class Solution {
public:
    queue<pair<pair<int,int>, int>> q;
    void bfs(vector<vector<int>> &mat, vector<vector<int>> &visited, vector<vector<int>> &dist){
       int n = mat.size(); 
        int m = mat[0].size();
        while(!q.empty()){
           auto temp = q.front();
            q.pop();
            int row = temp.first.first;
            int col = temp.first.second;
            int steps = temp.second;
            dist[row][col ]  =steps;
            int a[] = {0,1,0,-1};
            int b[] = {1,0,-1,0};
            
            for (int i = 0;i<4;i++){
                int nrow = row + a[i];
                int ncol = col + b[i];
                
                if (nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]==-1){
                    visited[nrow][ncol] =1;
                    q.push({{nrow,ncol},steps+1});
                }
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