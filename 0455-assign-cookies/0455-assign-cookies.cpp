class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int total = 0, index = 0;
        sort(g.begin(),g.end()); 
        sort(s.begin(),s.end());
        
        for (int i = 0;i<s.size();i++){
            if (s[i]>=g[index]){
                total++; index++;
                if (index== g.size()) break;
            } 
        } 
        
        return total;
    }
};