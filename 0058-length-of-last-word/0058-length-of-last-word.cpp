class Solution {
public:
    int lengthOfLastWord(string s) {
        int latest= 0;
        int localLength = 0;
        for (auto &i: s){
            if (i == ' '){ localLength = 0; continue; }
            else{
                localLength++; 
                latest = localLength;
            }
        }
        
        return latest;
    }
};