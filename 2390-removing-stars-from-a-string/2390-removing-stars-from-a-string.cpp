class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (int i =0;i<s.size();i++){
            if (s[i] =='*'){
                if (st.empty()) continue;
                st.pop(); continue;
            }
            
           st.push(s[i]);
        }
        
        s.clear();
        while(st.size()){
            s+= st.top(); st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};