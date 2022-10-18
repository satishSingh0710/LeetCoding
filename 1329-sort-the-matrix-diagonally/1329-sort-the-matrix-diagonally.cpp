class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
    
        // sorting through the first columns

        
        for (int i = 0;i<m;i++){
            sortt(mat, i,0);
        }
        
        for (int i = 1;i<n;i++){sortt(mat,0,i);}
        
        
        return mat;
    }
    
    
    void sortt(vector<vector<int>> &mat, int row, int col){
        int m = mat.size(), n = mat[0].size(), tempR = row, tempC = col;
        vector<int> temp;
        while(tempR < m && tempC<n){
            temp.push_back(mat[tempR][tempC]);
            tempR++; tempC++;
        }
        
        sort(temp.begin(), temp.end());
        int i = 0;
        while(row < m && col<n){
           mat[row][col] =  temp[i];
            row++; col++; i++;
        }
        
    }
};