class Solution {
public:
    int minOperations(string s) {
        if(s.size() == 1) return 0; 
        int tChanges = INT_MAX; 
        string temp = s; 
        int lChange = 0; 
        char req = '0'; 
        for (int i = 0;i<s.size();i++){
           if(temp[i] != req){lChange++;}
            if(req == '0') req = '1'; 
            else req = '0'; 
        }
        tChanges = min(tChanges, lChange);
        lChange = 0; 
        req = '1'; 
        for (int i = 0;i<s.size();i++){
           if(temp[i] != req){lChange++;}
            if(req == '0') req = '1'; 
            else req = '0'; 
        }
        tChanges = min(tChanges, lChange);
        return tChanges == INT_MAX?0:tChanges;
    }
};