//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> &visited, vector<int> &pathVisited,vector<int> adj[], int node){
        for (auto &i: adj[node]){
            if (visited[i] == -1){
                visited[i] = 1;
                pathVisited[i] = 1;
               if ( dfs(visited, pathVisited, adj, i) ) return true; 
                pathVisited[i] = -1;
            }else if (visited[i] == 1 && pathVisited[i] == 1){
                return true;
            }
        }
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> pathVisited(V, -1), visited(V, -1);
        for (int i = 0;i<V;i++){
            if (visited[i] == -1){
                visited[i] = 1;
                pathVisited[i] = 1;
                if (dfs(visited, pathVisited,adj,i)) return true;
                pathVisited[i] = -1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends