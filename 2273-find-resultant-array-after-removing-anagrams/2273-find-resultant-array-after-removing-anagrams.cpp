class Solution {
public:
    vector<string> removeAnagrams(vector<string>& w) {
        for (int i = 1;i<w.size();i++){
            string s1 = w[i-1];
            string s2 = w[i];
            sort(s1.begin(),s1.end()); 
            sort(s2.begin(),s2.end());
            if (s1==s2){
                w[i] = "#";
                w[i] = w[i-1];
                w[i-1] = "#";
            }
        }
        vector<string> res;
        for (auto &i: w){
            if (i!="#"){res.push_back(i);}
        }
        
        return res;
    }
};