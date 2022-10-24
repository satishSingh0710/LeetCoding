class Solution {
public:
    string res = "";
    string minRemoveToMakeValid(string s) {
        unordered_map<int, bool> mp;
        stack<int> st;
        for (int i = 0;i<s.size();i++){
            if (st.size() == 0 && s[i] == ')') {mp[i] = true;}
            else if (s[i] == ')'){
                st.pop();
            } else if (s[i] == '('){
                st.push(i);
            }
        }
        
        while (st.size()>0){
            mp[st.top()] = true;
            st.pop();
        }
        
        for (int i = 0;i<s.size();i++){
            if (mp[i] == true) continue;
            res+= s[i];
        }
        return res;
    }
};