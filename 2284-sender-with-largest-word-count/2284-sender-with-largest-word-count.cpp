class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        vector<int> word_count;
        unordered_map<string, int> mp;
        priority_queue<pair<int,string> > pq;
        for (int i  = 0;i<messages.size();i++){
            int count = 0;
            for (int j = 0;j<messages[i].size();j++){
                if (messages[i][j] == ' '){
                    count++;
                }
                if (j == messages[i].size()-1){
                    count++; word_count.push_back(count);
                }
            }
        }
        
        int j = 0;
        for (auto &i: senders){
            mp[i]+= word_count[j]; j++;
        }
        
        for (auto &i: mp){
            pq.push({i.second, i.first});
        }
        
        return pq.top().second;
        
        
    }
};