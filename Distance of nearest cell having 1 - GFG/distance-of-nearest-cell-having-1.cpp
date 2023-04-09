//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    queue<pair<pair<int,int>,int>> q;
        
    void bfs(vector<vector<int>> &mat, vector<vector<bool>> &visited,vector<vector<int>>&dist){
        int n = mat.size(); 
        int m = mat[0].size();
        while(!q.empty()){
           auto temp = q.front();
            q.pop();
            int row = temp.first.first;
            int col = temp.first.second;
            int steps = temp.second;
            dist[row][col ]  =steps;
            int a[] = {0,1,0,-1};
            int b[] = {1,0,-1,0};
            
            for (int i = 0;i<4;i++){
                int nrow = row + a[i];
                int ncol = col + b[i];
                
                if (nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]==false){
                    visited[nrow][ncol] = true;
                    q.push({{nrow,ncol},steps+1});
                }
            }
            
            
        }
            
}
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	    int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
       
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (mat[i][j]==1){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        
        bfs(mat,visited,dist); 
        return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends