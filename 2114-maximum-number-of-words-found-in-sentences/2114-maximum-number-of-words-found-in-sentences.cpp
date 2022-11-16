class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxxSize = INT_MIN;
        for (auto &i: sentences){
            int size = 1;
            for (int j = 0;j<i.size();j++){
                if (i[j] == ' '){
                    size++;
                }
            }
            
            maxxSize = max(maxxSize, size);
        }
        
        return maxxSize;
    }
};