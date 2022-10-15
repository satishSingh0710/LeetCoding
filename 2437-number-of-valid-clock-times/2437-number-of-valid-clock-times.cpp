class Solution {
public:
    int countTime(string t) {
        int count = 0; 
        for (auto &i: t){if (i=='?') count++; }
        if (count == 4) return 24 * 60 ;
        
        count = 1; 
        
        if (t[0]=='?')
        {
            if (t[1]=='?'){
                count *= 24;
            } else if (t[1]-'0' <= 3){
                count *= 3;
            } else{
                count *= 2;
            }
        }
        
        else if (t[1]=='?'){
            if (t[0] - '0'>= 2){count *=4; }
            else{
                count *= 10;
            }
        }
        
        
        if (t[3] == '?'){
            if (t[4]=='?'){
                count *= 60;
            } else if (t[4] != '?'){
                count *= 6;
            }
        }
        else if (t[4] == '?'){
            count*= 10; 
        }
        
        return count;
    }
};