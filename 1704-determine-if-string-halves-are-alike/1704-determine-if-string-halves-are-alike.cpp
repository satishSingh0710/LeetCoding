class Solution {
public:
    bool isVowel(char c){
        if (c == 'a' || c=='e'||c=='i'||c=='o'||c=='u'||c == 'A' || c=='E'||c=='I'||c=='O'||c=='U') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int i = 0, j = s.size()-1, firstHalfCount = 0, secondHalfCount = 0;
        while(i<j){
            if (isVowel(s[i])){
                firstHalfCount++;
            }
            if (isVowel(s[j])){
                secondHalfCount++;
            }
            
            i++; j--;
        }
        
        return firstHalfCount == secondHalfCount;
    }
};