class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool first = false;
        for (int i = 0;i<s.size();i++){
            if (s[i]=='|' && first == false){first = true; continue;}
            else if (s[i]=='|' && first == true){first = false; continue;}
            if (s[i]=='*' && first == false){count++;}
        }
        return count;
    }
};