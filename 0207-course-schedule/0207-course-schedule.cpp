class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses, 0);
        queue<int> q;
        for (auto &i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for (int i = 0;i<numCourses;i++){
            for (auto &j: adj[i]){
                inDegree[j]++;
            }
        }
        for (int i = 0;i<numCourses;i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++; 
            for (auto &i: adj[node]){
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }
        return count == numCourses;
        
    }
};