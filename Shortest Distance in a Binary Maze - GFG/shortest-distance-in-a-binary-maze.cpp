//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> a = {0,0,-1,1};
    vector<int> b = {1,-1,0,0};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
            
      if (grid[source.first][source.second] == 0) return -1;
        int res = -1;
        queue < pair < int, int >> q;
        q.push({
            source.first,
            source.second
        });
        int count = 0;
        while (q.size()) {
           int size = q.size();
            for (int x = 0; x < size; x++) {
                int row = q.front().first;
                int col = q.front().second;
                if(row == destination.first && col == destination.second){
                  res = count; return res;
                }
                q.pop();
                for (int i = 0;i<4;i++) {
                        int newRow = row + a[i];
                        int newCol = col + b[i];
                        if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() || grid[newRow][newCol] == 0) continue;
                        grid[newRow][newCol] = 0;
                        q.push({
                            newRow,
                            newCol
                        });
                    }
                }
                 count++;
        }
       return res;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends