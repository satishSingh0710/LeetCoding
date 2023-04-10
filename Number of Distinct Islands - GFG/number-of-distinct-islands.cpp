//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, int pRow, int pCol, vector<vector<int>> &grid, vector<vector<bool>> &visited,vector<pair<int,int>> &pairs){
         int m = grid.size();
         int n = grid[0].size();
        if (row < 0 || col<0 || row>=m || col>=n || visited[row][col] == true || grid[row][col]==0) return;
        visited[row][col] = true;
        pairs.push_back({row - pRow, col - pCol});
        dfs(row+1, col, pRow, pCol, grid, visited, pairs);
        dfs(row, col-1, pRow, pCol, grid, visited, pairs);
        dfs(row, col+1, pRow, pCol, grid, visited, pairs);
        dfs(row-1, col, pRow, pCol, grid, visited, pairs);
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<bool>> visited(m , vector<bool> (n, false));
        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                
                if (grid[i][j] == 1 && visited[i][j] == false){
                    vector<pair<int,int>> pairs;
                    dfs(i,j,i,j,grid, visited, pairs);
                    s.insert(pairs);
                }
                
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends