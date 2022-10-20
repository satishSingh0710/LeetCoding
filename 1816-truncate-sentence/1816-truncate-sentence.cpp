class Solution {
public:
    string truncateSentence(string s, int k) {
        string res = "";
        int count = 0;
        for (int i = 0;i<s.size();i++){
             if (s[i] == ' ' || i==s.size()-1) {
                 if (i == s.size()-1){res+= s[i];}
                 count++; if (count == k) return res;
             }
            
            res+= s[i];
        }
        
        return res;
    }
};