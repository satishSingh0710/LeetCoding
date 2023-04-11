class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int removeCount = 0;
        for (int i = s.size()-1;i>=0;i--){
            if (s[i] == '*'){
                removeCount++;
                continue;
            }else{
                if (removeCount>=1){
                    removeCount--; continue;
                }else{
                    st.push(s[i]);
                }
            }
        }
        
        string res = "";
        while(st.size()){
            res+= st.top(); st.pop();
        }
        return res;
    }
};