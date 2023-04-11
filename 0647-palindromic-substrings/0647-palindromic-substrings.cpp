class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> store(s.size(), vector<bool>(s.size(), false));
        for (int i = 0;i<s.size();i++){
            int row = 0, col = i;
            while(col < s.size() && row < s.size()){
                if(col - row == 0){
                    if (s[col] == s[row]) store[row][col] = true;
                }else if (col - row == 1){
                    if (s[row] == s[col]) store[row][col] = true;
                }else{
                    if (s[row] == s[col]){
                        store[row][col] = store[row+1][col-1];
                    }
                }
                row++; col++;
            }
        }
        
        int count = 0;
        for (int i = 0;i<store.size();i++){
            for (int j = 0;j<store.size();j++){
                if (store[i][j] == true) count++;
            }
        }
        
        return count;
    }
    
};