class Solution {
public:
    string reverseWords(string s) {
      vector<string> temp;
        stringstream ss(s);
        s.clear();
        while( ss >> s){
            temp.push_back(s);
        }
        
        s.clear();
        for(int i = temp.size()-1;i>=0;i--){
            if (i == 0){
                s+= temp[i]; break;
            }
            s+= temp[i] + " ";
        }
      return s;
    }
};