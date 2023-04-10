//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int clr(int i){
        return i == 1?0:1;
    }
    bool dfs(vector<int> &color, vector<int> adj[], int pColor, int edge){
        for (auto &i: adj[edge]){
            if (color[i] == -1){
                color[i] = clr(pColor);
                if(dfs(color, adj, color[i], i)) return true;
            }else{
                if (color[i]==pColor){
                    return true;
                }
            }
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    for (int i = 0;i<V;i++){
	        if (color[i] == -1){
	            color[i] = 1;
	            if (dfs(color, adj, 1, i)) return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends