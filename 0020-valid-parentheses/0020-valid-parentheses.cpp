class Solution {
public:
    bool isValid(stack<char> &st, char c){
        if (st.size() == 0) return false;
        if (c == ')' && st.top() != '(') return false;
        if (c == '}' && st.top() != '{') return false;
        if (c == ']' && st.top() != '[') return false;
        return true;
    }
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i] =='{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(isValid(st, s[i])){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if (st.size() == 0) return true;
        return false;
    }
};