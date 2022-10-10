class Solution {
public:
    string breakPalindrome(string p) {
        if (p.size()==1) return "";
          int n = p.size();   bool changed = false;     
        for (int i = 0;i<n;i++)
        {
            if (p[i]-'a' == 0) continue;
            if (n%2==1 && i == n/2) continue;
            if (p[i]-'a'>0){
               p[i]   = 'a'; changed = true; break;
            }
        }
        
        if (changed==false){
            p[n-1] = 'b';
        }
        
        return p;
    }
};