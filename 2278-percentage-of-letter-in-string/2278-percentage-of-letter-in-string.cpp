class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size(), count = 0;
        for (auto &i: s){
            if (i == letter) count++;
        }
        
        return (count*100)/n;
    }
};