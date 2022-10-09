class Solution {
public:
    bool check (char a, char b){
        
        if (a=='(' && b==')') return true;
        if (a=='{' && b=='}') return true;
        if (a=='['&& b==']') return true;
        else return false;
    }
    bool isValid(string s) {
        if (s.size()%2!=0)return false;
        stack<char> st;
        for (int i = 0;i<s.size();i++){
            if (s[i]=='('||s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }else{
                if (st.empty()) return false;
                char test = st.top();
                if (check(test,s[i])){
                    st.pop();
                }else return false;
            }
        }
        
        if (st.empty()) return true; else return false;
    }
};