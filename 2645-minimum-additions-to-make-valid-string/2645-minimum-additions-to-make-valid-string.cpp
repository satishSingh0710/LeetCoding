class Solution {
public:
    int addMinimum(string word) {
        int count = 0;
        int i = 0;
        char ch = 'a';
        while(i<word.size()){
            if (ch != word[i]){
                count++;
                
            }else{
                i++;
            }
            if (ch == 'a') ch = 'b';
            else if (ch == 'b') ch = 'c';
            else if (ch == 'c') ch = 'a';
        }
        if (word[word.size()-1] == 'a') count+=2;
        else if (word[word.size()-1] == 'b') count++;
        return count;
    }
};