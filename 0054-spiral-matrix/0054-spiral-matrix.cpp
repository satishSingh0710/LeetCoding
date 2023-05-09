class Solution {
public:
    void lToR(int firstRow, int firstCol, int lastCol, vector<vector<int>> &matrix, vector<int> &res){
         while(firstCol<=lastCol){
             res.push_back(matrix[firstRow][firstCol]); 
             firstCol++; 
         }
    }
    void tToD(int lastCol, int firstRow, int lastRow, vector<vector<int>> &matrix, vector<int> &res){
        while(firstRow<=lastRow){
            res.push_back(matrix[firstRow][lastCol]); 
            firstRow++;
        }
    }
    
    void rToL(int lastRow, int lastCol, int firstCol, vector<vector<int>> &matrix, vector<int> &res){
        while(firstCol<=lastCol){
            res.push_back(matrix[lastRow][lastCol]); 
            lastCol--; 
        }
    }
    void dToT(int firstCol, int lastRow, int firstRow, vector<vector<int>> &matrix, vector<int> &res){
        while(firstRow<=lastRow){
            res.push_back(matrix[lastRow][firstCol]);
            lastRow--; 
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int firstRow = 0, lastRow = matrix.size()-1, firstCol = 0, lastCol = matrix[0].size()-1;
        vector<int> res; 
        while(firstRow<=lastRow && firstCol<=lastCol){
            lToR(firstRow,firstCol,lastCol,matrix, res); 
            firstRow++;
            if(firstRow>lastRow) break;
            tToD(lastCol,firstRow,lastRow,matrix, res); 
            lastCol--; 
            if(firstCol>lastCol) break;
            rToL(lastRow, lastCol, firstCol, matrix, res); 
            lastRow--; 
            if(firstRow>lastRow) break;
            dToT(firstCol, lastRow, firstRow, matrix, res);
            firstCol++; 
            if(firstCol>lastCol) break;
        }
        return res; 
    }
};