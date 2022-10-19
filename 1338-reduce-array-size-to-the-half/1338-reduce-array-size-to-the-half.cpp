class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for (auto &i: arr){
            mp[i]++;
        }
        
        for (auto &i: mp){
            pq.push({i.second, i.first});
        }
        int size = arr.size(), nSize = size, count = 0;
        while(pq.size()>0 && size>nSize/2)
        {
            
                count++; size -= pq.top().first; pq.pop();
            
        }
        
        return count;
        
    }
};