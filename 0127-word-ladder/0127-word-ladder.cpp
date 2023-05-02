class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for (auto &i: wordList){st.insert(i);}
        queue<string> q;
        q.push(beginWord);
        int level = 2;
        while(!q.empty()){
            int size = q.size(); 
            for (int i = 0;i<size;i++){
                string curr = q.front(); q.pop(); 
                for (int j = 0;j<curr.size();j++){
                    string temp = curr;
                   for (char ch = 'a';ch<='z';ch++){
                        temp[j] = ch;
                       if (st.find(temp) != st.end()){
                           if (temp == endWord) return level;
                           st.erase(temp);
                           q.push(temp);
                       }
                  }   
                }
            }
            level++;
        }
        return 0;
    }
};