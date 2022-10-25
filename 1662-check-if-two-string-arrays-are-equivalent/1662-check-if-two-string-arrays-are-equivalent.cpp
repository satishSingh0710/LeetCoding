class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0,j=0;    // these are character pointers
        int x = 0,y = 0; // these are word pointers
        
        while(x<word1.size() && y<word2.size()){
            if (word1[x][i++] != word2[y][j++]) return false;
            if (i==word1[x].size()){
                i = 0; x++;
            }
            if (j == word2[y].size()){
                j = 0; y++;
            }
        }
        
        return x == word1.size() && y==word2.size();
    }
};