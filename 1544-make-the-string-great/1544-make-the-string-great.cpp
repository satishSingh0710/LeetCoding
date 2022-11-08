class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0;i<s.size();i++){
            if (st.size() == 0){
                st.push(s[i]);
                continue;
            }
            if (s[i]+32 == st.top() || s[i] - 32 == st.top()){
                st.pop(); continue;
            } 
            st.push(s[i]);
        }
        string ans = "";
        while(st.size()>0){
            ans += st.top(); st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};