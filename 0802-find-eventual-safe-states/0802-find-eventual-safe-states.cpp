class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> adj[size], revAdj[size];
        vector<int> safe, inDegree(size, 0); 
        queue<int> q;
        for(int i = 0;i<size;i++){
            adj[i] = graph[i];
        }
        
        for (int i = 0;i<size;i++){
            for (auto  &j: adj[i]){
                revAdj[j].push_back(i);
            }
        }
        for (int i = 0;i<size;i++){
            for (auto &j: revAdj[i]){
                inDegree[j]++;
            }
        }
        for (int i = 0;i<size;i++){
            if (inDegree[i] == 0)q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            safe.push_back(node); 
            for (auto &i: revAdj[node]){
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }
        sort(safe.begin(), safe.end()); 
        return safe;
    }
};