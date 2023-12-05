class Solution {
public:
    string comp(string a, string b){
        if(b.size() < 3) return ""; 
        if(b[0] != b[1] || b[1] != b[2] || b[0] != b[2]) return ""; 
        if(a.size() > b.size()) return a; 
        if(b.size() > a.size()) return b; 
        int i = 0; 
        while(i< a.size()){
            if(a[i] > b[i]) return a;
            if(a[i] < b[i]) return b; 
            i++; 
        }
        return a; 
    }
    string largestGoodInteger(string num) {
        string res = ""; 
        for (int i = 0;i<num.size();i++){
            string temp = comp(res, num.substr(i,3));
            if(temp != ""){res = temp;}
        }
        return res; 
    }
};