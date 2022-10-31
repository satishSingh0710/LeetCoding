class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        vector<pair<int,int>> start;
        for (int i = 0;i<matrix.size();i++){
            start.push_back({i,0});
        }
        for (int i = 1;i<matrix[0].size();i++){
            start.push_back({0, i});
        }
        
        return check(matrix, start); 
    }
    
    bool check(vector<vector<int>> &matrix, vector<pair<int,int>> &start){
    
        for (int i = 0;i<start.size();i++){
            int row = start[i].first, col = start[i].second, element = matrix[row][col];
            while(row<matrix.size() && col < matrix[0].size()){
                if (matrix[row][col]!= element){
                    return false;
                } row++; col++; 
            }
        }
        return true;
    }
};