class Solution {
public:
    string breakPalindrome(string p) {
        if (p.size()==1) return "";
        int n = p.size();      
        for (int i = 0;i<n;i++)
        {
            if (p[i]=='a') continue;
            if (n%2==1 && i == n/2) continue;
            if (p[i]!='a'){
               p[i] = 'a'; return p;
            }
        }
        
        p[n-1] = 'b';
        return p;
    }
};