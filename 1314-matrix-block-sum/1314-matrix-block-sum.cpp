class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                int sum = 0,startr = i-k,endr = i+k,startc = j-k,endc = j+k;
                for (int x = startr;x<=endr;x++){
                    for (int y = startc;y<=endc;y++){
                        if (x>=0&&x<n&&y>=0&&y<m){
                            sum+= mat[x][y];
                        }
                    }
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};