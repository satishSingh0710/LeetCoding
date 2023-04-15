class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()], revAdj[graph.size()];
        vector<int> safe, inDegree(graph.size(), 0); 
        queue<int> q;
        for(int i = 0;i<graph.size();i++){
            adj[i] = graph[i];
        }
        
        for (int i = 0;i<graph.size();i++){
            for (auto  &j: adj[i]){
                revAdj[j].push_back(i);
            }
        }
        for (int i = 0;i<graph.size();i++){
            for (auto &j: revAdj[i]){
                inDegree[j]++;
            }
        }
        for (int i = 0;i<graph.size();i++){
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